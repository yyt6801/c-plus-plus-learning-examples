#include <windows.h>
//有问题，能运行但不出现窗体

LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst, LPSTR args,int ncmdshow)
{
    //MessageBox(NULL,TEXT("hello world !!!"),TEXT("Note"),MB_OK);
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowsClass";
    wc.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wc))
        return -1;

    CreateWindow(TEXT("myWindowClass"),TEXT("My Window"),WS_OVERLAPPEDWINDOW | WS_VISIBLE,100,100,500,500,
                    NULL,NULL,NULL,NULL);
    MSG msg = {0};

    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
    

}

LRESULT CALLBACK WindowProcedure(HWND hWnd,UINT msg,WPARAM wp,LPARAM lp)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    
    default:
        return DefWindowProcW(hWnd,msg,wp,lp);
    }
}