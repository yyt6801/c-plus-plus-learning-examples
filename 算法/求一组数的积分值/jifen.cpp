#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//ok!!!   求一数组的积分
#define  NEWNUM 1000

float get_jifen(int rawnum,float *rawdata)
{
	float newdata[NEWNUM]={};
	float sum[NEWNUM]={};
	for(int i=0;i<NEWNUM;i++)
	{
		int lowlim = floor((float)(rawnum-1)/(NEWNUM-1)*i);
		int uplim = ceil((float)(rawnum-1)/(NEWNUM-1)*i);

		if(lowlim==uplim)
			newdata[i] = rawdata[lowlim];
		else
			newdata[i] = rawdata[lowlim]+(rawdata[uplim]-rawdata[lowlim])/(uplim-lowlim)*((float)(rawnum-1)/(NEWNUM-1)*i-lowlim);		
	}

	for(int i=0;i<NEWNUM-1;i++)
		sum[i+1]=sum[i]+(abs(newdata[i])+abs(newdata[i+1]))/NEWNUM/2;

	return sum[NEWNUM-1];
}
int main()
{
	int rawnum=20;
	//float rawdata[20] ={1.275,1.682,2.449,2.849,2.959,3.124,2.933,1.7,0.613,1.538,1.673,0.713,-0.684,-0.028,0.305,0.107,0.13,0.041,-0.157,0.227,};
float rawdata[20] ={
0.061,0.144,0.227,0.266,0.156,0.105,0.053,-0.075,-0.051,-0.236,-0.136,-0.337,-0.368,-0.256,-0.306,-0.381,-0.444,-0.329,-0.225,0.443
};

	float test = get_jifen(rawnum,rawdata);

	printf("sum= %f",test);

	system("pause");
}