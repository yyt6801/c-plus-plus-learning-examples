typedef struct
{
    uid_t uid;   /* owner`s user id */
    gid_t gid;   /* owner`s group id */
    udi_t cuid;  /* creator`s user id */
    gid_t cgid;  /* creator`s group id */
    mode_t mode; /* read-write permissions 0400 MSG_R 0200 MSG_W*/
    ulong_t seq; /* slot usage sequence number*/
} ipc_perm;

typedef stuct
{
    struct ipc_perm msg_perm; /* read_write perms */
    struct msg *msg_first;    /* ptr to first message on queue */
    struct msg *msg_last;     /* ptr to last message on queue */
    msglen_t msg_cbytes;      /* used bytes current on queue */
    msgqnum_t msg_qnum;       /* current num of message on queue */
    msglen_t msg_qbytes;      /* max # of bytes allowed on queue */
    pid_t msg_lspid;          /* pid of last msgsnd() */
    pid_t msg_lrpid;          /* pid of last msgrcv() */
    time_t msg_stime;         /* time of last msgsnd() */
    time_t msg_rtime;         /* time of last msgrcv() */
    time_t msg_ctime;         /* time of last msgctl() */
}
msqid_ds;

typedef struct
{
    long mtype;
    char mbuf[MSGLEN];
} Message;