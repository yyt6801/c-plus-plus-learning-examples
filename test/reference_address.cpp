#include <iostream>
 
using namespace std;
 
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
 
double& setValues( int i )
{
  return vals[i];   // 返回第 i 个元素的引用
}



int main ()
{
  // 引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。
  int i =1345;
  int& dd = i;
  printf("i的值为%d   dd的值为%d\n",i,dd);//i的值和dd的值完全一样，一个变动则另一个也跟着变
  dd = 4;
  printf("i的值为%d   dd的值为%d\n",i,dd);
  i = 123;
  printf("i的值为%d   dd的值为%d\n",i,dd); 

  int a,b=123;
  swap(a,b);
  printf("a的值为%d,,,b的值为%d\n",a,b);


   setValues(1)=1234; // 改变第 2 个元素
   setValues(3)=1234;  // 改变第 4 个元素
 
   cout << "改变后的值" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
   return 0;
}
  
// 函数定义
void swap(int& x, int& y)
{
   int temp;
   temp = x; /* 保存地址 x 的值 */
   x = y;    /* 把 y 赋值给 x */
   y = temp; /* 把 x 赋值给 y  */
  
   return;
}
