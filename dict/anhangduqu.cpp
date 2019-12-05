#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024
int main()
{
    const char *aim_code = "abc";
    char buf[MAX_LINE]; /*缓冲区*/
    FILE *fp;           /*文件指针*/
    int len;            /*行字符个数*/
    if ((fp = fopen("dict.txt", "r")) == NULL)
    {
        perror("fail to read");
        exit(1);
    }
    while (fgets(buf, MAX_LINE, fp) != NULL)
    {
        len = strlen(buf);
        buf[len - 1] = '\0'; /*去掉换行符*/

        if (strcmp(buf, aim_code) == 0)
        {
            printf("%s %d \n", buf, len - 1);
        }
    }
    return 0;
}