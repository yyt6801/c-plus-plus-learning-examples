#include "test.h" //问题:c_cpp_properties.json中添加了全局头文件,但这里无法找到
#include <stdio.h>
int main()
{
    int a = 1;
    int b = 5;
    int c = add_ab(a, b);
    printf("%d", c);
}