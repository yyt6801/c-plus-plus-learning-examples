#include <stdio.h>
#include <windows.h>
#include <wininet.h>
#include "tchar.h"
#include <iostream>
#define MAXSIZE 1024
#pragma comment(lib, "Wininet.lib")
void urlopen(_TCHAR *);
//int _tmain(int argc, _TCHAR* argv[])
int main(int argc, char *argv[])
{
    //char *s = "https://www.baidu.com";

    char s[30];

    gets(s); /*遇到回车认为输入结束*/

    TCHAR Name[100];
#ifdef UNICODE
    MultiByteToWideChar(CP_ACP, 0, s, -1, Name, 100);
#else
    strcpy(Name, s);
#endif

    urlopen(Name);

    system("pause");
    return 0;
}
void urlopen(_TCHAR *url)
{
    HINTERNET hSession = InternetOpen(_T("UrlTest"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (hSession != NULL)
    {
        HINTERNET hHttp = InternetOpenUrl(hSession, url, NULL, 0, INTERNET_FLAG_DONT_CACHE, 0);
        if (hHttp != NULL)
        {
            wprintf_s(_T("%s\n"), url);
            BYTE Temp[MAXSIZE];
            ULONG Number = 1;
            while (Number > 0)
            {
                InternetReadFile(hHttp, Temp, MAXSIZE - 1, &Number);
                Temp[Number] = '\0';
                printf("%s", Temp);
            }
            InternetCloseHandle(hHttp);
            hHttp = NULL;
        }
        InternetCloseHandle(hSession);
        hSession = NULL;
    }
}
