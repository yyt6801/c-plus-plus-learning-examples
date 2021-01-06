#include <stdio.h>
#include <string.h>
int main()
{
    char root[80];
    memset(root, 0x00, sizeof(root));

    char *aim_code;
    scanf("%s", aim_code);

    strcat(root, "E:/files/InformationSecurity/data/DICT/");
    strcat(root, (const char *)aim_code[0]);
    strcat(root, "/");

    if (aim_code[0] >= 97 && aim_code[0] <= 122)
        aim_code[0] = aim_code[0] - 32;
    strcat(root, (const char *)aim_code[0]);
    strcat(root, "-");
    strcat(root, (const char *)aim_code[1]);
    strcat(root, ".txt");
    //	strcat(str_longsize,buff);
    // root = "DICT/" + aim_code[0] + "/" + aim_code[0] + "-" + aim_code[1] + ".txt";
    printf("%s\n", root);
    getchar();
}
