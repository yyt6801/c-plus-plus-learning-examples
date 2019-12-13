/***************************************************
Function:
    int msgget(ket_t key,int oflag);
Explain:
    create or view a message queue
Return :
    a int indetify
Include:
    sys/msg.h
introduction:
    oflag: 0400 msg_r 
        0200 msg_w
        0600 msg_wr
    ipc_creat: NO exist and then creat a queue
          exist : reference a queue
    ipc_creat|ipc_excl: NO exist and then creat a queue
              exist : return error
****************************************************/
#include <stdio.h>
#include <sys/msg.h>
#include <stdlib.h>

int MsgGet(int key)
{
    int ret;
    ret = msgget(key, 0600 | IPC_CREAT);
    //   ret=msgget(key,0600|IPC_CREAT|IPC_EXCL);
    if (ret < 0)
        perror("creat msgid error");
    printf("msgid=%d/n", ret);
    system("ipcs -q -i ret");
    return ret;
}
int main(int argc, char *agrv[])
{
    int key;
    printf("pleasse input msgkey:");
    scanf("%d", &key);
    MsgGet(key);
    return 0;
}