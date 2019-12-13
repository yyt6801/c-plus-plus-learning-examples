/**********************************************************
Function:
    int msgctl(int msqid,int cmd,struct msqid_ds *buff)
Explain:
    cdm: IPC_RMID; delete msqid 
       IPC_SET: 
       IPC_STAT: return msqid stat
 
*********************************************************/
#include "typemsg.h"
int MsgCtl(int msqid, int cmd, struct msqid_ds *buff)
{
    int ret;
    ret = msgctl(msqid, cmd, buff);
    if (ret < 0)
    {
        perror("msgctl error");
        return -1;
    }
    return 0;
}

int main()
{
    int msqid, type;
    struct msqid_ds info;
    printf("please input msqid /nand type(1:icp_rmid;2:ipc_stat)");
    scanf("%d%d", &msqid, &type);
    if (type == 1)
    {
        MsgCtl(msqid, IPC_RMID, NULL);
        printf("delete queue success:%d/n", msqid);
    }
    else if (type == 2)
    {
        MsgCtl(msqid, IPC_STAT, &info);
        printf("get queue stat:%d/n", msqid);
    }
    return 0;
}