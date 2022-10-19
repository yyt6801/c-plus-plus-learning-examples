#include <stdio.h>
#include <string.h>
#include <nlohmann/json.hpp>
#include "tinyxml2.h"
using namespace nlohmann;


int main()
{
	std::string tagname;
	std::string type;
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLError error = doc.LoadFile("TagList.xml");
	if (error != tinyxml2::XML_SUCCESS) {
		//std::cout << "读取 xml 失败：" << doc.ErrorStr() << std::endl;
		return EXIT_FAILURE;
	}
	tinyxml2::XMLElement* root = doc.RootElement();
	tinyxml2::XMLElement* tagNode = root->FirstChildElement("tag");
	int tag_num = 0;
	while (tagNode != NULL)
	{
		tagname = tagNode->Attribute("name");
		type = tagNode->Attribute("type");
		//printf("Name of tag : %s\n", tagname.c_str());
		//printf("type of tag : %s\n", type.c_str());
		tagNode = tagNode->NextSiblingElement();//下一个兄弟节点
		tag_num++;
	}

	return 0;
}
