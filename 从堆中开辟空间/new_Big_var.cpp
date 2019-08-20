// //new 定义大数组，用来防止定义变量过多导致栈溢出--OK
// //用new 从堆中开辟空间
// #include <stdio.h>
// #include <iostream>
// using namespace std;
// int main()
// {
// 	//第一种方式  定义一位数组
// 	double *array;
// 	array = new double[80*1000];//定义80*1000 大小,double类型
// 	////访问的时候*(array+i*y+j)表示array[i][j]
// 	for(int i=0;i<80;i++){
// 		for(int j=0;j < 1000;j++){
// 			*(array+i*1000+j) = i+j;
// 		}
// 	}
// 	cout<<"记录集变量CPCRec赋值成功！第55行,333个数为"<<*(array+55*1000+333)<<endl;
// }

//------------------------------------------------------------------------
//例2 定义一个二维数组
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
		double **array1;
		array1 = new double *[80];
		for(int i=0;i<80;++i)
			array1[i] = new double[1000];
		//...用的时候可以直接array1[i][j]
		for(int i=0;i<80;i++){
			for(int j=0;j < 1000;j++){
				array1[i][j] = i+j;
			}
		}
	cout<<"记录集变量CPCRec赋值成功！"<<array1[50][333]<<endl;
	//需注意及时delete
		for(int i=0;i<80;++i)
			delete[] array1[i];
	delete[] array1;
}
