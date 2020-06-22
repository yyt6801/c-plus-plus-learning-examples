#include <stdio.h>

int main()
{
    int a = 123;
    int* p = &a;
    int *m = &a;
    printf("%x\n",p);//p的值
    printf("%x\n",*p);
    printf("%x\n",&p);//p的地址
    
    
    printf("%x\n",m);//m的值
    printf("%x\n",*m);
    printf("%x\n",&m);//m的地址,新开辟的空间

    printf("%x\n",a);//*p 代表的是 a 的值
    printf("%x\n",&a);
    

}