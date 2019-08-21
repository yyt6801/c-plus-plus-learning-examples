//字符串拼接，把int型数据，拼接为一个大字符串，中间以逗号隔开
#include <stdio.h>
#include <tchar.h>
#include <string.h>
int main ()
{
	double xx[10];
	xx[0] = 34.342;
	xx[1] = 331.3121;
	xx[2] = 25323.34;
	xx[3] = 35323.34;
	xx[4] = 45323.34;
	xx[5] = 14155323.342341;
	xx[6] = 6533.34;
	xx[7] = 7523.34;
	xx[8] = 8323.34;
	char stringx[500];
	memset(stringx,0x00,sizeof(stringx));

	char c[10]; 
	for (int i = 0; i < 9; i++)
	{
		memset(c,0x00,sizeof(c));
		sprintf(c,"%f",xx[i]); 
		strcat(stringx,c);
		strcat(stringx,",");
	}
    puts(stringx);
	return 0;
}