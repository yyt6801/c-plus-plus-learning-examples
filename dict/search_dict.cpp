
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <io.h>

//#include <sstream>//stringstream  ss;需要用到---具体用法???
using namespace std;

#define MAX_LINE 2048
#define IMGNUM 20000 //图片所在文件夹中图片的最大数量
char img_files[IMGNUM][1000];

int getFiles(char *path)
{
    int num_of_img = 0;
    long hFile = 0;
    struct _finddata_t fileinfo;
    char p[700] = {0};
    strcpy(p, path);
    strcat(p, "\\*");
    if ((hFile = _findfirst(p, &fileinfo)) != -1)
    {
        do
        {
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    continue;
            }
            else
            {
                //strcpy(img_files[num_of_img], path);
                //strcpy(img_files[num_of_img], "\\");
                //strcat(img_files[num_of_img], "\\");
                //strcat(img_files[num_of_img++], fileinfo.name);
                strcpy(img_files[num_of_img++], fileinfo.name);
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
    return num_of_img;
}
int main()
{
    char root[180];
    memset(root, 0x00, sizeof(root));

    char aim_code[20];
    scanf("%s", aim_code);

    char xxx[1];
    memset(xxx, 0x00, sizeof(xxx));

    strcpy(root, "DICT/");

    if (aim_code[0] >= 97 && aim_code[0] <= 122)
        xxx[0] = aim_code[0] - 32;

    root[strlen(root)] = xxx[0];
    strcat(root, "/");

    //
    int num = getFiles(root);
    int i, j;
    for (i = 0; i < num; ++i)
    {
        //printf("%s\n", img_files[i]);
        for (j = 2; j < 20; j++)
        {
            if (img_files[i][j] == aim_code[1])
            {
                strcat(root, img_files[i]);
                printf("%s\n", root);
                break;
                break;
            }
        }
    }

    /*root[41] = aim_code[0];
	strcat(root, "-");
	root[43] = aim_code[1];
	strcat(root, ".txt");*/
    //printf("%s\n", root);
    //system("pause");

    char buf[MAX_LINE]; /*缓冲区*/
    FILE *fp;           /*文件指针*/
    int len;            /*行字符个数*/
    int rownum = 0;
    if ((fp = fopen(root, "r")) == NULL)
    {
        printf("cannot read %s", root); //输出目标密码和对应行数
        system("pause");
        perror("fail to read");
        exit(1);
    }
    while (fgets(buf, MAX_LINE, fp) != NULL)
    {
        len = strlen(buf);
        buf[len - 1] = '\0'; /*去掉换行符*/

        rownum++;
        if (strcmp(buf, aim_code) == 0)
        {
            fgets(buf, MAX_LINE, fp);
            printf("%s %d \n", buf, rownum); //输出目标密码和对应行数
            system("pause");
            return 0;
        }
    }
    printf("cannot get password!\n");
    system("pause");
    return 0;
}
