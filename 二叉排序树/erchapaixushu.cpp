
#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef struct BiTNode
{ // 二叉树的儿二叉链表结点结构

    int data;                        // 结点结构
    struct BiTNode *lchild, *rchild; // 左右孩子指针

} BiTNode, *BiTree;

/**
 * 递归查找二叉排序树 T 中是否存在 key
 * 指针 f 指向 T 的 双亲，其初始调用值为NULL
 * 若查找成功，则指针 p 指向该数据元素结点，并返回TRUE
 * 若查找不成功， 则指针 p 指向查找路径上访问的最后一个结点并返回FALSE
 */
int SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{

    if (!T)
    { // 查找不成功
        *p = f;
        return FALSE;
    }
    else if (key == T->data)
    {

        *p = T;
        return TRUE;
    }
    else if (key < T->data)
    { // 在左子树中继续查找

        return SearchBST(T->lchild, key, T, p);
    }
    else
    { // 在右子树中鸡血查找

        return SearchBST(T->rchild, key, T, p);
    }
}

/**
 * 二叉排序树的插入
 * 当二叉排序树中不存在关键字等于 key 的数据元素时，插入 key 并返回TRUE
 */
int InsertBST(BiTree *T, int key)
{

    BiTree p, s;

    if (!SearchBST(*T, key, NULL, &p))
    { // 没找到key

        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;

        if (!p)
            *T = s; // 插入 s 为新的根结点
        else if (key < p->data)
            p->lchild = s; //插入 s 为左孩子
        else
            p->rchild = s; // 插入 s 为右孩子

        return TRUE;
    }
    else
        return FALSE;
}

/**
 * 从二叉排序树中删除结点 p ， 并重接它的左/右子树
 */
int Delete(BiTree *p)
{

    BiTree q, s;

    if ((*p)->rchild == NULL)
    { // 右子树空 则只需要重接它的左子树

        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else if ((*p)->lchild == NULL)
    { // 左子树空 则只需要重接它的右子树

        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else
    { // 左右子树都不空

        q = *p;
        s = (*p)->lchild;

        while (s->rchild)
        { // 向右到尽头，找到待删结点的前驱

            q = s;
            s = s->rchild;
        }

        (*p)->data = s->data; // s 指向被删除结点的直接前驱 （将被删结点前驱的值取代被删结点的值）

        if (q != *p)
            q->rchild = s->lchild; // 重接 q 的右子树
        else
            q->lchild = s->lchild; // 重接 q 的左子树

        free(s);
    }

    return TRUE;
}

/**
 * 二叉排序树的删除
 * 当二叉排序树中存在关键字等于 key 的数据元素时，删除该数据元素并返回TRUE
 */
int DeleteBST(BiTree *T, int key)
{

    if (!*T) // 不存在关键字等于 key 的元素
        return FALSE;
    else
    {

        if (key == (*T)->data)
            return Delete(T);
        else if (key < (*T)->data)
            return DeleteBST(&(*T)->lchild, key);
        else
            return DeleteBST(&(*T)->rchild, key);
    }
}

/**
 * 中序递归遍历
 */
void InOrderTraverse(BiTree T)
{

    if (!T)
        return;

    InOrderTraverse(T->lchild);
    printf("%d ", T->data);
    InOrderTraverse(T->rchild);
}

int main(int argc, const char *argv[])
{

    int i;
    int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};

    BiTree T = NULL;
    for (i = 0; i < 10; i++)
    { // 通过插入操作来构建二叉排序树
        InsertBST(&T, a[i]);
    }

    printf("中序递归遍历二叉排序树：\n");
    InOrderTraverse(T);
    printf("\n\n");

    DeleteBST(&T, 93);
    printf("删除结点 93 后的结果为：\n");
    InOrderTraverse(T);
    printf("\n\n");

    printf("插入 91 后的结果为：\n");
    InsertBST(&T, 91);
    InOrderTraverse(T);
    printf("\n\n");

    system("pause");
    return 0;
}