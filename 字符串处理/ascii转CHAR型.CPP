#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    // char str[10]; //数组定义是从栈中开辟空间，可修改； char *str 为指针定义，相当于在静态存储区中定义常量，在编译时已定好空间大小，只读无法修改；
    // str[0] = 89;
    // // str[1] = 121;
    // str[1] = 0x79; //也可使用16进制
    // str[2] = 116;
    // str[3] = 6 + '0'; //int型后加上+'0'，可将int型转化为char型???因为ascII码中0是48
    // str[4] = '8';
    // str[5] = 48;
    // str[6] = '0' + 1;
    // str[7] = '\0';

    char str[10] = {0b01011001, 0x79, 116, 6 + '0'};
    // char str[10] = {0131, 0x79, 116, 6 + '0'}; //八进制头部为0开始；十六进制为0x开始；二进制为0b开始

    printf("%s\n", str);
}
