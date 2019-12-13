/*********************************************************************
Function:
    int msgrcv(int msqid,const void *ptr,size_t msglen,long type,int flag)
Explain:
    recv message order by type 
    msgrcv error: Argument list too long --> msglen的长度小于消息体中消息的长度
Para :
    ptr: point to message struct 
    msglen: 由ptr指向的缓冲区中数据部分的大小,这个是该函数能够返回的最大数据量
    type: message type;
 
              1> 0:返回队列中最早的消息
              2> 大于0:返回消息队列中类型为type的第一个消息
              3> 小于0:返回消息队列中类型小于或者等于type的绝对值的消息类型中最小的第一个消息
    flag: 0<wait> 没有消息或者消息类型不符合的时候,线程等待
         响应: 1>有一个所请求类型的消息可以获取
            2>msqid的消息队列被系统删除,返回一个EIDRM
            3>调用线程被某个捕获的信号所中断
       IPC_NOWAIT:在没有数据的情况下,立即返回一个ENOMSG错误
       MSGNOERROR:当所接受的消息数据部分大于msglen长度时,获取截短的数据部分,否则返回E2BIG错误
Return:
    message len
*********************************************************************/
#include "typemsg.h"
int MsgRcv(int msqid, char *buf, int msglen, long type, int flag)
{
    int ret;
    ret = msgrcv(msqid, buf, msglen, type, flag);
    if (ret < 0)
        perror("msgrcv error");
    system("ipcs -q");
    return ret;
}

int main()
{
    int msqid, len;
    long ttype;
    Message mbuf;
    printf("msgrcv:please input recv msqid:");
    scanf("%d", &msqid);
    MsgRcv(msqid, (char *)&mbuf, 8900, 0, IPC_NOWAIT);
    printf("recv message=%s/n", mbuf.mbuf);
    Put_String((unsigned char *)&mbuf, sizeof(Message));
    return 0;
}