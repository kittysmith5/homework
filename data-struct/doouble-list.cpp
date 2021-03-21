#include <iostream>
typedef int ElemType;

typedef struct DLNode
{
    ElemType data;
    struct DLNode *next, *prior;

} DLNode, *DLinkList;
using namespace std;
bool InitDList(DLinkList &L)
{
    L = (DLinkList)malloc(sizeof(DLNode));

    if (L == NULL)
    {
        return false;
    }

    L->next = NULL;
    L->prior = NULL;

    return true;
}
//在p节点后插入s节点
bool InsertNextDNode(DLNode *p,DLNode *s){
    s->next = p->next;
    if (p->next !=NULL)
    {
        p->next->prior=s;//排除最后一个元素的可能性
    }
    s->prior = p;
    p->next = s;
    return true;
}
//删除p结点的后继结点
bool DelectNextDNode(DLNode *p){
    if (p==NULL)
    {
        return false;
    }
    DLNode *q = p->next;
    if (q==NULL)
    {
        return false;
    }
    p->next = q->next;
    if (q->next!=NULL)
    {
        q->next->prior = p;
    }
    free(p);
    return true;  
}

//双链表的销毁
void DestroyDList(DLinkList L){
    while (L->next !=NULL)
    {
        DelectNextDNode(L);
    }
    free(L);
    L=NULL; //头指针指向L
}


/*遍历开始*/
//向前遍历
void DescPrintDLst(DLinkList L){
    DLNode *p = L;
    while (p->prior!=NULL)
    {
        cout<<p->data<<"\t";
        p=p->prior;
    }  
}

//向后遍历

/*遍历结束*/
int main()
{
    DLinkList L;
    InitDList(L);
    return 0;
}