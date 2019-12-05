#include <stdio.h>
#include <io.h>
#include <string.h>
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
                strcpy(img_files[num_of_img], path);
                strcat(img_files[num_of_img], "\\");
                strcat(img_files[num_of_img++], fileinfo.name);
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
    return num_of_img;
}
int main()
{
    char path[] = "../test";
    int num = getFiles(path);
    int i;
    for (i = 0; i < num; ++i)
    {
        printf("%s\n", img_files[i]);
    }
    return 0;
}
// ———————————————— 版权声明：本文为CSDN博主「小咸鱼_」的原创文章，遵循 CC 4.0 BY - SA 版权协议，转载请附上原文出处链接及本声明。 原文链接：https: //blog.csdn.net/sinat_30071459/article/details/53178356