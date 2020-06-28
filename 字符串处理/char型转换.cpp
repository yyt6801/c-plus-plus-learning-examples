#include <stdio.h>
#include <tchar.h>
#include <iostream>//system("pause");需要
#include "string.h"//strcpy函数需要
#include <string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	char aa[]="HelloWorld!";					//char[]
	printf("%s\n",aa);
	printf("%c+%c\n",aa[4],aa[5]);

	char *b=aa;							//char[] -> char*
	printf("%s\n",b);

	const char *c=b;					//char* -> const char*
	printf("%s\n",c);

	char *d;
	d=const_cast<char*>(c);				//const char* -> char*
	printf("%s\n",d);
	strcpy(d,c);						//const char* -> char*
	printf("%s\n",d);

	char *m;
	m="2019-04-18 13:27:08";
	printf("%s\n",m);

	//sprintf把float型转为char型
	float a_num = 354.23564;
	char buffer[32];
	sprintf(buffer,"%f",a_num);         //float  ->   char [20]
	printf("buffer:  %s\n",buffer);

	//sprintf把float型转为string型
	float b_num = 5345.2535;
	string buffer_s;
	sprintf(buffer,"%f",b_num);         //float  ->   string
	printf("buffer:  %s\n",buffer);

	system("pause");

	return 0;

}