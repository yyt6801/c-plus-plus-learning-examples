
#include <windows.h>
#include "tchar.h"
int main()
{
    char strUsr[10] = "Hello";
    TCHAR Name[100];
#ifdef UNICODE
    MultiByteToWideChar(CP_ACP, 0, strUsr, -1, Name, 100);
#else
    strcpy(Name, strUsr);
#endif

    system("pause");
    return 0;
}