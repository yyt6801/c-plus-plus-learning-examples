#include <stdio.h>
#include <cstdlib> //malloc需要的标准库
//单链表定义
typedef struct list
{
	int data;
	struct list * next;
}list,*linklist;

//单链表的创建
void create(linklist &L,int n)
{
	int i;
	linklist p;
	L = (linklist)malloc(sizeof(list));
	L->next = NULL;
	for(i=0;i<n;i++)
	{
		p = (linklist)malloc(sizeof(list));
		scanf("%d",&p->data);
		p->next = L->next;
		L->next = p;
	}
}

//单链表输出
void show(linklist L)
{
	linklist p;
	p = L->next;
	while(p)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
}

//直接插入排序
void insertsort(linklist L)
{
	linklist p,q,pre;
	p = L->next->next;//p为L的第二个结点
	L->next->next = NULL;//把L置为单结点的链表
	while(p)
	{
		q = p->next;//p的下一个结点
		pre = L;//p的前一个结点
		while(pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}
int main(){
    linklist   L;
    create(L,5);
    show(L);
    insertsort(L);
    show(L);
}