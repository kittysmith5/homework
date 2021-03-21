#include <iostream>
// 不带头节点的链表
using namespace std;

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 初始化链表
void InitList(LinkList L)
{
    L = NULL;
}

//判空
bool Empty(LinkList L)
{
    return L == NULL;
}
bool InsertNextNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }

    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
// 插入
bool ListInsert(LinkList L, int i, ElemType e)
{
    if (i < 1)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }

    if (i == 1)
    {

        s->data = e;
        s->next = L; //指向之前的一个节点
        L = s;       //L是第一个节点,应该是把s的值赋给L;
        return true;
    }

    int j = 1;
    LNode *p = L;
    while (p && i - j > 1)
    {
        p = p->next;
        j++;
    }
    return InsertNextNode(p, e);
}

int main()
{
    LinkList L;
    InitList(L);
    return 0;
}