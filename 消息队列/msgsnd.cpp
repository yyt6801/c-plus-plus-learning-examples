/***********************************************************************************
Function:
    int msgsnd(int msqid,const void *ptr,size_t length,int flag)
Explain:
    send a message to a queue
Return:
    len: send message len;
Include:
    sys/msg.h
Introduction:
    flag: 0 : if queue full wait:1>具备存放新消息的空间
                   2>由msqid标识的消息队列从系统中删除(返回EIDRM错误)
                   3>调用线程被某个捕获的信号所中断(返回EINTR错误)
       IPC_NOWAIT:如果没有存放新消息的空间,函数马上返回
                   1>指定的队列中有太多的字节
                   2>在系统范围存在太多的消息
*****************************************************************************************/
#include "typemsg.h"
int MsgSnd(int msqid, char *buf, int len, int flag)
{
    int ret;
    ret = msgsnd(msqid, buf, len, flag);
    if (ret < 0)
        perror("msgsnd error");
    system("ipcs -q");
    return ret;
}

int main()
{
    int msqid, len, stype;
    Message msgb;
    memset(&msgb, 0, sizeof(Message));
    printf("msgsnd:please input msqid:");
    scanf("%d", &msqid);
    printf("please input msgtype:");
    scanf("%d", &stype);
    msgb.mtype = stype;
    strcpy(msgb.mbuf, "zhangweia");
    MsgSnd(msqid, (char *)&msgb, sizeof(Message), 0);
    return 0;
}