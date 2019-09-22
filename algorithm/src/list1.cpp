//
// Created by cxl on 19-9-10.
//
#include <iostream>
using namespace std;
//预定义常量和类型
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100 //线性表初始的存储空间的初始分配量
#define LISTINCREMENT 10
typedef int Status;
typedef int ValueType;
typedef struct LNode{
    ValueType value;
    struct LNode *next;
}LNode,*List;

//初始化链表

Status Get_List_LNode(List lNode,int i,ValueType e){
    List p;
    int j;
    p=lNode->next;//初始化,p指向第一个节点
    j=1;//j为计数器
    while(p &&j<i){
        p=p->next;
        ++j;
    }
    //判断位置是否合法
    if(!p ||j>i) return ERROR;

    e=p->value;
    return OK;
}
Status List_Insert_L(List &list,int i,ValueType e){
    //在带头节点的单链表list中的第i个位置之前插入元素e
    List p,s;
    int j;
    p=list;
    j=0;
    //寻找第i-1个位置
    while(p && j<i-1){
        p=p->next;
        ++j;
    }
    if (!p ||j>i-1) return ERROR;
    s=(List)malloc(sizeof(LNode));
    s->value=e;
    s->next=p->next;
    p->next=s;

    return OK;
}
Status List_Delete_L(List &list,int i,ValueType &e){
    //在带头节点list中,删除第i个元素,并返回删除的值赋给e
    List p,s;
    int j;
    p=list;
    j=0;
    while(p->next &&j<i-1){
        p=p->next;
        ++j;
    }
    if (!(p->next) || j>i-1) return ERROR;
    s=p->next;
    p->next=s->next;
    e=s->value;
    free(s);
    return OK;

}
void CreateList_L(List &list,int n){
    int i;
    List p;
    list= static_cast<List>(malloc(sizeof(LNode)));
    list->next=NULL;
    cout<<"请输入"<<n<<"个数据"<<endl;
    for (int j = n; j>0; --j) {
        p= static_cast<List>(malloc(sizeof(LNode)));
        cin>>p->value;
        p->next=list->next;
        list->next=p;
    }
}
void create_(List &list,int n){
    int i;
    List p;
    list= static_cast<List>(malloc(sizeof(LNode)));
    list->next=NULL;
    cout<<"请输入"<<n<<"个数据"<<endl;
    for (int j = n; j >0; --j) {
        p= static_cast<List>(malloc(sizeof(LNode)));
        cin>>p->value;
        p->next=list->next;
        list->next=p;
    }
}
void CreateList_L2(List &L,int n){
    int i;
    List p,q;
    L= static_cast<List>(malloc(sizeof(LNode)));
    p=L;
    L->next=NULL;
    cout<<"请输入"<<n<<"个数据"<<endl;
    for (int j = 0; j < n; ++j) {
        q= static_cast<List>(malloc(sizeof(LNode)));
        cin>>q->value;
        q->next=p->next;
        p->next=q;
        p=q;
    }
}
void DestroyList(List &list){
    List p,q;
    p=list->next;
    while(p!=NULL){
        q=p->next;
        free(p);
        p=q;
    }
}

void showList(List &list){
    List  p=list->next;
    while(p!=NULL){
        cout<<p->value;
        p=p->next;
        if (p!=NULL){
            cout<<"-->";
        }

    }
    cout<<endl;
}

int main(){
    LNode node;
    List list=&node;

    CreateList_L2(list,5);
    cout<<"创建后的链表"<<endl;
    showList(list);

//    List_Insert_L(list,3,10);
//    showList(list);
//
//    int e;
//    List_Delete_L(list,2,e);
//    cout<<"删除后的线性表"<<endl;
//    showList(list);
//    cout<<"删除的数值为:"<<e<<endl;
//    Get_List_LNode(list,3,e);
//    showList(list);
//    cout<<"查询的数值为:"<<e<<endl;


    DestroyList(list);
    return 0;
}