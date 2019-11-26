#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char *str;
    str[0] = 89;
    str[1] = 121; //int型后加上+'0'，可将int型转化为char型???因为ascII码中0是48
    str[2] = 116;
    str[3] = '\0';
    printf("%s\n", str);
}
