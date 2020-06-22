#include <stdio.h>

int main()
{
    int a = 123;   //61ff1c

    int *p = &a;//   p  61ff1c       *p=a错

    printf("%x\n",p);//p的值     
    printf("%d\n",*p);//          0x...   
    printf("%x\n",&p);//p的地址
    
    
    printf("%d\n",a);//*p 代表的是 a 的值  123
    printf("%x\n",&a);//          0x...
    

}