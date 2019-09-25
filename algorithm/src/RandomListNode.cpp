////
//// Created by cxl on 19-9-16.
////
////复杂的链表的深度拷贝
///**
// * 已知一个{复杂}的链表.节点中有一个指向本链表任意某个节点的随机指针(也可能为空),求这个链表的深度拷贝
// */
//#include <iostream>
//#include <map>
//#include <vector>
//
//using namespace std;
//
//struct RandomListNode{
//    int label;
//    RandomListNode *next,*random;
//    RandomListNode(int x): label(x),next(NULL),random(NULL){}
//};
//class Solution{
//public:
//    RandomListNode *copyRandomList(RandomListNode *head){
//        map<RandomListNode *,int> node_map;
//        vector<RandomListNode *> node_vec;//新的链表
//        RandomListNode *ptr=head;
//        int i=0;
//        while(ptr){//将新链表节点push入node_vec,生成新链表节点位置到地址的map
//            node_vec.push_back(new RandomListNode(ptr->label));
//            node_map[ptr]=i;//对啦 //记录原链表地址到节点位置的node_map
//            ptr=ptr->next;//遍历原链表
//            i++;//记录节点位置
//        }
//        node_vec.push_back(0);
//        ptr=head;
//        i=0;//再次遍历原始链表的next指针,random指针
//        while(ptr){
//            node_vec[i]->next=node_vec[i+1];//不会   //连接新链表的next指针
//            if (ptr->random){//当random指针不空时
//                int id=node_map[ptr->random];
//                  node_vec[i]->random=node_vec[id];//node_map[ptr->random]=id;
//            }
//            ptr=ptr->next;
//            i++;
//        }
//        return node_vec[0];
//    }
//
//};
//int main(){
//    RandomListNode a(1);
//    RandomListNode b(2);
//    RandomListNode c(3);
//    RandomListNode d(4);
//    RandomListNode e(5);
//    a.next=&b;
//    b.next=&c;
//    c.next=&d;
//    d.next=&e;
//    a.random=&c;
//    b.random=&d;
//    c.random=&c;
//    e.random=&d;
//    Solution solution;
//
//    RandomListNode *head=solution.copyRandomList(&a);
//
//    while(head){
//        cout<<"label="<<head->label<<"  ";
//        if (head->random){
//            cout<<"rand="<<head->random->label<<endl;
//        } else{
//            cout<<"rand="<<"NULL"<<endl;
//        }
//        head=head->next;
//    }
//
//}
//
//
////必备知识map
////int main(){
////    map<RandomListNode *,int > node_map;
////    RandomListNode a(5);
////    RandomListNode b(3);
////    RandomListNode c(6);
////    a.next=&b;
////    b.next=&c;
////    a.random=&c;
////    b.random=&a;
////    c.random=&c;
////    node_map[&a]=1;
////    node_map[&b]=2;
////    node_map[&c]=3;
////    cout<<node_map[a.random]<<endl;
////    cout<<node_map[b.random]<<endl;
////    cout<<node_map[c.random]<<endl;
////}