////字符串常用处理： 右去零-左补空格---需加#include <splitstr.h>头文件
#include <stdio.h>
#include <cstring>
#include "splitstr.h"
#include <iostream>
using namespace std;
int main()
{
    char mat_no[20] = "H1345   ";
    char left_zero[10] = "000abcde";

    //通过trim_r(char *t)实现对字符串后去空格
    CSPLITSTR::trim_r(mat_no);

    //通过TrimLeftZeroStr(char *ibuf)实现对字符串左去'0'
    CSPLITSTR::TrimLeftZeroStr(left_zero);
    
    cout<< mat_no << "123" <<endl;
    cout<< "123" << left_zero << "123" <<endl;
    return 0;
}