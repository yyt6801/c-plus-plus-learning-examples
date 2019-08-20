#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a=12.257902012398877;
    double b=12.257902012398877;
    const float PI=3.1415926;         // 常量定义
    cout<<setprecision(15)<<a<<endl;  // float只有6-7位有效数字，后面的就不精确
    cout<<setprecision(15)<<b<<endl;  // double有15-16位有效数字，所以完全正确
    cout<<setprecision(15)<<PI<<endl; 
    cout<<setprecision(3)<<PI<<endl; //保留3位有效数字
    return 0;
}