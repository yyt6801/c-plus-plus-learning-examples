注释 
//
/*...*/

定义 #define
#define TOTAL_NUMBER 100

枚举 enum
enum days {SUN = 1, MON, TUE, WED, THU, FRI, SAT};

导入头文件 #include 
#include <stdio.h>
<尖括号>中是c标准库的头文件
外部头文件使用双引号代替尖括号
#include "my_function.h"

函数可以事先在.h文件中定义
也可直接在.c文件头部定义

如果函数调用在main()方法之后，那么必须提前声明在main()之前
int add(int a, int b);  //声明

程序入口是一个返回值为整型的main()函数
int main(){}

printf打印标准输出，%d为整数，\n为换行
printf("%d\n",123); 打印123    
所有语句以分号;结束

在使用变量之前必须先声明它们
变量在声明时需要知名其类型，类型能够告诉系统该变量所占用的内存空间

//int 型   占用4个字节
int a = 123;

//short 型   占用2个字节
short b = 123;

//char 字符型    占用1个字节
char c = 1;
char d = 'a';

//long 长整型 占用4到8个字节
long e = 123;

//float 浮点型    用32位标识的浮点数字
float f = 123.456;

//double 双精度浮点型    用64位表示的浮点数字
double g = 123.456;

整数类型也可以有无符号的类型表示，无符号整数能表示的范围比原来整数大一些
unsigned short a;
unsigned int b;
unsigned long c;

单引号中的字符时机器的字符集中的整数
'0' // => 在ASCII字符集中对应48
'A' // => 在ASCII字符集中对应65

char类型占用1字节
sizeof(obj)查看占用字节
printf("%zu\n",sizeof(int)); // => 4 

