//调用WindowsAPI编程--MessageBox--模态对话框
#include <windows.h>
//WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)

{
	ShowWindow(FindWindow("ConsoleWindowClass",0),0);//让程序运行时不显示窗口控制台
	int result;
 	result = MessageBox(NULL, TEXT("这是我第一次调用WindowsAPI编程--MessageBox--模态对话框！"), TEXT("木马程序！"), MB_ICONEXCLAMATION | MB_YESNO );//MB_ICONEXCLAMATION | MB_OKCANCEL| MB_ICONQUESTION | MB_DEFBUTTON2
    switch(result)
	{
	//case IDYES: MessageBox(NULL,TEXT( "YOU click yes!"),TEXT("alert"),MB_DEFBUTTON2);
	case IDYES: MessageBox(NULL,TEXT( "YOU click yes!"),TEXT("alert"),MB_DEFBUTTON2);
	return 0;
	case  IDNO: MessageBox(NULL,TEXT( "YOU click NO!"),TEXT("alert"),MB_ICONSTOP);
	}
	return 0;

}