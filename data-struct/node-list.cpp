#include <iostream>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void InitList(LinkList &L);
void PrintList(LinkList L);
int Length(LinkList L);
LNode *LocateElem(LinkList L,ElemType e);
bool DeleteNode(LNode *p);
bool ListDelete(LinkList &L, int i, ElemType &e);
bool InsertPriorNode(LNode *p, ElemType e);
bool InsertNextNode(LNode *p, ElemType e);
bool ListInsert(LinkList &L, int i, ElemType e);
bool Empty(LinkList L);
LinkList List_TailInsert(LinkList &L);
LinkList List_HeadInsert(LinkList &L);


using namespace std;
//尾插法
LinkList List_TailInsert(LinkList &L){
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    LNode *s,*r=L;
    cin>>x;
    while (x!=-9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        //s->next = r->next;
        r->next =s;
        r=s;
        cin>>x;
    }
    r->next = NULL;
    return L;
}
//头插法
LinkList List_HeadInsert(LinkList &L){
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next =NULL;
    LNode *s;
    cin>>x;
    while (x!=-9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;

        s->next = L->next;
        L->next =s;
        cin>>x;
    }
    return L;
}
// 初始化链表
void InitList(LinkList &L)
{
    if (L == NULL)
    {
        cout << "内存已满!" << endl;
    }
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
}
//判空
bool Empty(LinkList L)
{
    return L->next == NULL;
}
// 按位序插入
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
    {
        return false;
    }
    LNode *p = L; //好扫描,p每次变化,相当于临时存储!
    int j = 0;
    while (p && i - j > 1)
    {
        p = p->next;
        j++;
    }
    if (!p)
    {
        return false; //扫描完后为空
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));

    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 在节点后插入元素
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
//前插操作
bool InsertPriorNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }

    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e; //O(1)的算法;
    return true;
}

bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (L == NULL)
    {
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p && i - j > 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        return false;
    }
    if (p->next == NULL)
    {
        return false;
    }
    LNode *q = p->next;
    e = q->data;       //返回删除的值
    p->next = q->next; //修改指针即可
    free(q);
    return true;
}
//删除指定节点后的元素
bool DeleteNode(LNode *p)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *q = p->next;

    p->data = q->next->data; //q->next可能是NULL
    p->next = q->next;
    free(q);
    return true;
}
//按位查找,查询第n个节点

LNode *GetElem(LinkList L, int i){
    if (i<0)
    {
        return NULL;
    }
    LNode *p =L;
    int j=0;
    while (p&&j<i)
    {
        p=p->next;
        j++;
    }
    return p; 
}

LNode *LocateElem(LinkList L,ElemType e){
    LNode *p = L->next;
    int j=0;
    while (p&&p->data!=e)
    {
        p=p->next;
    }
    return p;
}
void PrintList(LinkList L){
    LNode *p=L->next;
    while (p)
    {
        cout<<p->data<<"\t";
        p= p->next;
    }
    cout<<endl;
}
int Length(LinkList L){
    LNode *p = L->next;
    int len=0;
    if (p)
    {
        p=p->next;
        len++;
    }
    return len;
}
int main()
{
    LinkList L;
    //InitList(L);
    List_TailInsert(L);//-9999
    PrintList(L);
    return 0;
}