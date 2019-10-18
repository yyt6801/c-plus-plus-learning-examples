#include <windows.h>
#include "tchar.h"
int main()
{
    char *ConvertLPWSTRToLPSTR(LPWSTR lpwszStrIn)
    {
        LPSTR pszOut = NULL;
        if (lpwszStrIn != NULL)
        {
            int nInputStrLen = wcslen(lpwszStrIn);

            // Double NULL Termination
            int nOutputStrLen = WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, NULL, 0, 0, 0) + 2;
            pszOut = new char[nOutputStrLen];

            if (pszOut)
            {
                memset(pszOut, 0x00, nOutputStrLen);
                WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, pszOut, nOutputStrLen, 0, 0);
            }
        }
        return pszOut;
    }
    system("pause");
    return 0;
}
//转自链接：https://blog.csdn.net/B_H_L/article/details/7581519