//用法:strncpy(sub,string+12,13)/*将string中从string[12]开始的13个数字复制到sub中*/
//例 ok! 把string[25]的前19位字符复制到a中
#include <iostream>
#include "string.h"
using namespace std;
int main()
{
	#define size 200//
	char a[size];
	memset(a,0x00,sizeof(a));
	char string[25]= "2007-12-20 18:31:34:123";
	strncpy(a,string,19);
	cout<<a<< endl;
	system ("pause");
	return 0;  
}