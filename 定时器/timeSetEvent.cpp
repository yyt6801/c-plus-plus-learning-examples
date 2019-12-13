// MMRESULT timeSetEvent（ UINT uDelay,
//     UINT uResolution,
//     LPTIMECALLBACK lpTimeProc,
//     WORD dwUser,
//     UINT fuEvent ）

//     uDelay：以毫秒指定事件的周期。
//     Uresolution：以毫秒指定延时的精度，数值越小定时器事件分辨率越高。缺省值为1ms。
//     LpTimeProc：指向一个回调函数。
//     DwUser：存放用户提供的回调数据。
//     FuEvent：指定定时器事件类型:
//      TIME_ONESHOT: uDelay毫秒后只产生一次事件
//      TIME_PERIODIC: 每隔uDelay毫秒周期性地产生事件。

#include <stdio.h>
#include <Windows.h>
#include <Mmsystem.h>
#pragma comment(lib, "Winmm.lib")
// //声明
void WINAPI
onTimeFunc(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dwl, DWORD dw2);
//函数
void WINAPI onTimeFunc(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dwl, DWORD dw2)
{
    printf("timer begin\n");
}

//入口
int main()
{
    MMRESULT timer_id;
    int n = 0;
    timer_id = timeSetEvent(3000, 1, (LPTIMECALLBACK)onTimeFunc, DWORD(1), TIME_PERIODIC);
    //***code***
    // if (timer_id == 0)
    // {
    //     printf("timeSetEvent() failed with error %d\n", GetLastError());
    //     return 0;
    // }
    // while (n < 20)
    // {
    //     printf("Hello World\n");
    //     Sleep(2000);
    //     n++;
    // }
    Sleep(7000);
    timeKillEvent(timer_id); //释放定时器
    return 1;
}