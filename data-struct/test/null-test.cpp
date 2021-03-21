#include <iostream>
// 不带头节点的链表
using namespace std;


typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode, *LinkList;
// 初始化链表
void InitList(LinkList L){
    L = NULL;
}

// 没错
// NULL就是0的意思
// 空指针一般指向NULL
//判空
bool Empty(LinkList L){
    return L == NULL;
}
int main(){
    LinkList L;
    InitList(L);
    return 0;
}