#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float getAVG_sqrt(float* cpcx_data,int a,int b,float* cpcx_sqrt){
	//若b<a,则返回0
	if (a<=0 || b<a || b<=0)
	{
		*cpcx_sqrt = 0;
		return 0;//返回均值
	}
	//求均值
	float summ=0;
	for (int i = a; i < b; i++)
	{
		summ += *(cpcx_data+i);
	}
	float CPCxdata_AVG = summ/(b-a);
	//求标准差
	summ=0;
	for(int k= a; k < b; k++)
	{
		summ +=(cpcx_data[k]-CPCxdata_AVG)*(cpcx_data[k]-CPCxdata_AVG);
	}
	//*cpcx_sqrt=sqrt(summ/(b-a));//标准差用地址返回
	//return CPCxdata_AVG;//返回均值

	*cpcx_sqrt = double(int(sqrt(summ / (b - a)) * 1000)) / 1000;//标准差用地址返回
	CPCxdata_AVG = double(int(CPCxdata_AVG * 1000)) / 1000;
	return CPCxdata_AVG;//返回均值
}
int main()
{
    float x[10]={0};
    float y[10]={0};
    float stdev=0;
    int a=0,b=0;
    float avg = getAVG_sqrt(x,a,b,&stdev);
    printf("avg=%f,stdev=%f",avg,stdev);

}