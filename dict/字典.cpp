#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char (*list)[20], int high, char *str); //函数声明

int main()
{
    FILE *fp;                      //定义文件指针
    char str[20];                  //存放待查询关键字
    char Z[8000][20], C[8000][20]; //定义两个数组用于存放编码和中文
    int sum = 0;                   //用于数组计数
    int num;                       //用于判断是否查找到结果

    fp = fopen("C://Users//Administrator//Desktop//tcc//trans//in.txt", "r"); //打开文件，写入模式
    if (fp == NULL)                                                           //若fopen()函数返回NULL则打开文件失败
    {
        printf("文件打开失败\n");
        exit(0); //退出
    }

    while (!feof(fp)) //如果读取成功，则重复读
    {
        fscanf(fp, "%s%s", Z[sum], C[sum]); //将文件中的内容读出并保存到数组中
        sum++;                              //计数
    }
    fclose(fp); //关闭文件

    while (1)
    {
        printf("请输入需要查询的内容(输入-1表示结束)：\n");
        scanf("%s", str);

        if (strcmp(str, "-1") == 0) //如果输入-1则退出
        {
            printf("谢谢使用！\n");
            exit(0);
        }

        num = find(&Z[0], sum - 1, str); //调用查找函数，将返回值赋值给num

        if (num == -1)
            printf("未查找到内容\n"); //比较完所有内容，还是未找到查找的内容
        else
            printf("查询结果为： %s %s\n", Z[num], C[num]); //找到需要查找的内容，输出结果
    }

    return 0;
}

//进行关键词查找，返回对应序号
int find(char (*list)[20], int max, char *str) //char (*list)[20]表示一个指针数组
{
    int i;

    for (i = 0; i <= max; i++)
    {
        if (strcmp(list[i], str) == 0)
            return i; //如果查找成功，返回mid
    }

    return -1; //全部找完未找到，返回-1
}
// ———————————————— 版权声明：本文为CSDN博主「*pan」的原创文章，遵循 CC 4.0 BY - SA 版权协议，转载请附上原文出处链接及本声明。 原文链接：https: //blog.csdn.net/qq_33523925/article/details/89428100