#include <iostream>
#include "string.h"
using namespace std;
int main()
{
	#define size 200//

	char a[size];
	memset(a,0x00,sizeof(a));
	char string[25]= "2007-12-20";

	strcpy(a,string);
	strcat(a,".txt");
	cout<<a<< endl;
	system ("pause");
	return 0;  
}