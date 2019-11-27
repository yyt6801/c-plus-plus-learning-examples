#include <iostream>
#include <Windows.h>
using namespace std;

#define BUF_SIZE 4096
HANDLE H_Mutex = NULL;
HANDLE H_Event = NULL;

int main(int argc, char **argv)
{
    //1:创建共享文件句柄
    HANDLE shared_file = CreateFileMapping(
        INVALID_HANDLE_VALUE, //物理文件句柄
        NULL,                 //默认安全级别
        PAGE_READWRITE,       //PAGE_READWRITE表示可读可写， PAGE_READONLY表示只读， PAGE_WRITECOPY表示只写
        0,                    //高位文件大小
        BUF_SIZE,             //地位文件大小
        "ShareMemory"         //共享内存名称
    );
    if (shared_file == NULL)
    {
        cout << "Could not create file mapping object..." << endl;
        return 1;
    }

    //2：映射缓存区视图，得到指向共享内存的指针
    LPVOID lpBUF = MapViewOfFile(
        shared_file,         //已创建的文件映射对象句柄
        FILE_MAP_ALL_ACCESS, //访问模式：可读写
        0,                   //文件偏移的高32位
        0,                   //文件偏移的低32位
        BUF_SIZE             //映射视图的大小
    );
    if (lpBUF == NULL)
    {
        cout << "Could not create file mapping object...." << endl;
        CloseHandle(shared_file);
        return 1;
    }
    H_Mutex = CreateMutex(NULL, FALSE, "sm_mutex");
    H_Event = CreateEvent(NULL, FALSE, FALSE, "sm_event");

    //3:操作共享内存
    char Buffer[97];
    while (1)
    {
        cout << "A process:Please input the content to the process B" << endl;
        cin.getline(Buffer, 97);
        cout << "Buffer: " << Buffer << endl;
        WaitForSingleObject(H_Mutex, INFINITE); //使用互斥体加锁
        memcpy(lpBUF, Buffer, strlen(Buffer) + 1);
        ReleaseMutex(H_Mutex); //放锁
        SetEvent(H_Event);
    }

    CloseHandle(H_Mutex);
    CloseHandle(H_Event);

    //4:解除映射和关闭句柄
    UnmapViewOfFile(lpBUF);
    CloseHandle(shared_file);
    return 0;
}