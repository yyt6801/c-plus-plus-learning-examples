
#include <stdio.h>
#include <stdlib.h>
 
//定义节点
typedef struct node{
    char data;
    struct node * next;
}node;
 
//定义队列（保存队首和队尾指针）
typedef struct queue_link{
    node * front;
    node * rear;
}que;
 
//初始化队列
que * InitQueue()
{
    que * q = (que*)malloc(sizeof(que));
    q->front = q->rear = NULL;
    return q;
}
 
//判断队列是否为空
int EmptyQueue(que * q)
{
    return q->front == NULL;
}
 
//入队
void InsertQueue(que *q, char data)
{
    node * n = (node *)malloc(sizeof(node));
    if(n == NULL)//内存分配失败
        return ;
    n->data = data;
    n->next = NULL;//尾插法，插入元素指向空
    if(q->rear == NULL)
    {
        q->front = n;
        q->rear = n;
    }
    else{
       q->rear->next = n;//让n成为当前的尾部节点下一节点
        q->rear= n;//尾部指针指向n
    }
 
}
 
//出队(删除队首元素)
void DeleteQueue(que *q)
{
    node * n = q->front;
    if(q->front == NULL)//判断队列是否为空
        return ;
    if(q->front == q->rear)//是否只有一个元素
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else{
        q->front = q->front->next;
        free(n);
    }
 
}
 
//打印队列
void Display(que * q)
{
    node * n = (node *)malloc(sizeof(node));
    n = q->front;
    if(n == NULL)
    {
        return ;//队列为空
    }
    while(n != NULL)
    {
        printf("%c ",n->data);
        n = n->next;
    }
    printf("\n");
}
int main()
{
    int i=5,j=5;
    que * q;
    q = InitQueue();
    printf("begin in line :\n");
    while(i--)
    {
        printf("element %c in line , queue:",'A'+i);
        InsertQueue(q,'A'+i);
        Display(q);
    }
    printf("begin out line:\n");
    while(j--)
    {
        printf("no. %d  element in line, queue:",5-j);
        DeleteQueue(q);
        Display(q);
    }
    printf("\n");
    return 0;
}