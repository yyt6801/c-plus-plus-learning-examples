
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1 = "Hello";
    string bbb[3] ={"H12354","H12354","H12354"} ;
    //printf("%s",str1);    //无法用printf打印出c++的string类型字符串
	  // printf("%s",(bbb[1] + "sssss"));
    string str2 = bbb[1]+"H12354";    //string类型的字符串可以直接使用+进行字符串拼接

    cout<< str1 << endl;
    cout<< str2 << endl;
}