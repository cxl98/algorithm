//
// Created by cxl on 19-9-9.
//
#include <iostream>
using namespace std;
//预定义常量和类型
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1 //不可行的
#define OVERFLOW -2 //溢出
#define LIST_INIT_SIZE 100 //线性表初始的存储空间的初始分配量
#define LISTINCREMENT 10
typedef struct {
    int *elem;
    int length;
    int listsize;
}SqList;

//初始化线性表
int init_List_SqList(SqList &L){
    //构造一个线性表
    L.elem= (int *)(malloc(LIST_INIT_SIZE * sizeof(int)));
    if (!L.elem) exit(OVERFLOW);//分配空间失败,退出程序
    L.length=0;//空表长度为0
    L.listsize=LIST_INIT_SIZE;//初始化链表长度
    return OK;
}

//创建线性表

int create_List_Sq(SqList &L,int n){
    int *newbase;
    int i;
    if (n<0) return ERROR;
    if (n>L.length){
        newbase= static_cast<int *>(realloc(L.elem, (L.listsize + n) * sizeof(int)));
        if (!newbase) exit(OVERFLOW);
        L.elem=newbase;
        L.listsize+=n;
    }
    L.length=n;
    cout<<"请输入数据,用空格分隔"<<endl;
    for (int i = 0; i < L.length; ++i) {
        cin>>L.elem[i];
    }
    return OK;
}
//在线性表 指定的位置插入数据
int ListInsert_Sq(SqList &L,int index, int e){
    int *newbase,*q,*p;
    if(index<1 || index>L.length){
        return ERROR;
    }
    if (L.length> L.listsize){
        newbase= static_cast<int *>(realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int)));
        if(!newbase) exit(OVERFLOW);
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    q=&(L.elem[index-1]);
    for (p=&(L.elem[L.length-1]); p >=q ;p--) {
        *(p+1)=*p;

    }
    * q=e;
    ++L.length;
    return OK;
}

//删除线性表指定的位置的数值,并返回删除的数值保存到temp中;
int ListDelete_Sq(SqList &L,int index, int &temp){
    int *p,*q;
    if(index<1 || index>L.length) return ERROR;
    p=&(L.elem[index-1]);
    temp=*p;
    q=L.elem+L.length-1;
    for (++p;p<=q;++p){
        *(p-1)=*p;
    }
    --L.length;
    return OK;
}
int compare(int a,int b){
    if (a==b) return TRUE;

    return FALSE;
}


int LocateElem_Sq(SqList L,int e,int (*compare) (int ,int)){
    int i;
    int *p;
    i=1;
    p=L.elem;
    while(i<L.length&&!(*compare)(*p++,e)){
        ++i;
    }
    if(i<L.length) return i;

    return 0;
}

int DestroyList_Sq(SqList &L){
    if(L.elem){
        free(L.elem);
    }
    return OK;
}

int ShowList_Sq(SqList &L){
    int i;
    if (L.length<=0) return ERROR;

    for (int j = 0; j <L.length ; ++j) {
        cout<<L.elem[j]<<endl;
    }
    return OK;
}
int  main(){
    SqList L;
    init_List_SqList(L);
    cout<<L.length<<"\t"<<L.listsize<<endl;

    create_List_Sq(L,5);
    ShowList_Sq(L);

    ListInsert_Sq(L,2,3);
    cout<<"插入后的线性表"<<endl;
    ShowList_Sq(L);
    int e;
    ListDelete_Sq(L,1,e);
    cout<<"删除后的线性表"<<endl;
    ShowList_Sq(L);
    cout<<"删除的数值为:"<<e<<endl;

    int i=LocateElem_Sq(L,1,compare);
    cout<<"查询的位置是:"<<i<<endl;

    DestroyList_Sq(L);
    return 0;
}