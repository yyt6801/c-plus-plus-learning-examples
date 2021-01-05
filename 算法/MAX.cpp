#include <stdio.h>
	template<class Type>
	static  inline Type Max(const Type xa[], int n)
	{
		int  i;
		Type Max = xa[0];

		for (i = 1; i < n; i++)
		{
			if (xa[i] > Max)
			{
				Max = xa[i];
			}
		}

		return (Max);
	}	
// 查找数组的最大值
int main(){
    
    int xa[10]={12,34,43,52,12,43,2,6,2,6};
	int a= Max(xa,10);
    printf("%d",a);
}