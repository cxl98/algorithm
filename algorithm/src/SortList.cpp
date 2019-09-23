////
//// Created by cxl on 19-9-16.
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//struct SortList{
//    int  data;
//    SortList *next;
//    SortList(int x) :data(x),next(NULL){}
//};
//bool cmp(const SortList *a,const SortList *b){
//    return a->data < b->data;
//}
//class Solution{
//public:
//    SortList * mergeTwoLists(SortList *l1, SortList *l2){
//        SortList temp_head(0);
//        SortList *pre=&temp_head;
//        while(l1&&l2){              //将pre与较小的节点连接
//            if (l1->data<l2->data){
//                pre->next=l1;
//                l1=l1->next;
//            }
//            else{
//                pre->next=l2;
//                l2=l2->next;
//            }
//            pre=pre->next;//pre指向新连接的节点
//        }
//        if (l1){
//            pre->next=l1;
//        }
//        if (l2){
//            pre->next=l2;
//        }
//        return temp_head.next;
//    }
//    //排序
//    SortList *merge_N_List(vector<SortList *> &lists){
//        vector<SortList *> node_vec;
//        for (int i = 0; i <lists.size() ; ++i) {
//            //SortList *head= (SortList *) lists;
//            SortList *head= lists[i];
//            while(head){
//               node_vec.push_back(head); //node_vec[i]->data=head->data;我的答案
//                head=head->next;
//            }
//        }
//        if (node_vec.size()==0){
//            return NULL;
//        }
//        sort(node_vec.begin(),node_vec.end(),cmp);
//        for (int j = 1; j <node_vec.size() ; ++j) {
//            node_vec[j-1]->next=node_vec[j];
//        }
//        node_vec[node_vec.size()-1]->next=NULL;
//        return node_vec[0];
//    }
//    //分制
//    SortList *mergeNLists(vector<SortList *> &lists){
//        if (lists.size()==0){
//            return NULL;
//        }
//        if (lists.size()==1){
//            return lists[0];//对
//        }
//        if (lists.size()==2){
//            return mergeTwoLists(lists[0],lists[1]);
//        }
//        int mid=lists.size()/2;//对
//        vector<SortList *> sub1_lists;
//        vector<SortList *> sub2_lists;
//        for (int i = 0; i <mid ; ++i) {
//            sub1_lists.push_back(lists[i]);
//        }
//        for (int j = mid; j <lists.size() ; ++j) {
//            sub2_lists.push_back(lists[j]);
//        }
//        SortList *l1=merge_N_List(sub1_lists);//对
//        SortList *l2=merge_N_List(sub2_lists);//对
//        return mergeTwoLists(l1,l2);        //对
//    }
//};
////int main(){
////    SortList a1(1);
////    SortList b1(4);
////    SortList c1(6);
////    a1.next=&b1;
////    b1.next=&c1;
////    SortList a2(0);
////    SortList b2(5);
////    SortList c2(7);
////    SortList d2(8);
////    a2.next=&b2;
////    b2.next=&c2;
////    c2.next=&d2;
////    Solution solution;
////    SortList *head=solution.mergeTwoLists(&a1,&a2);
////    while(head){
////        cout<<head->data<<endl;
////        head=head->next;
////    }
////
////}
//
////==============排序链表的合并(多个)方法2:排序后合并=======================
////bool cmp(const SortList *a,const SortList *b){
////    return a->data<b->data;
////}
////int main(){
////    SortList a(3);
////    SortList b(0);
////    SortList c(7);
////    SortList d(1);
////    vector<SortList *> node;
////    node.push_back(&a);
////    node.push_back(&b);
////    node.push_back(&c);
////    node.push_back(&d);
////    sort(node.begin(),node.end(),cmp);
////    for (int i = 0; i <node.size() ; ++i) {
////        cout<<node[i]->data<<endl;
////    }
////}
////==============排序链表的合并(多个)方法3:分制后相连=======================
//int main(){
//    SortList a(1);
//    SortList b(4);
//    SortList c(6);
//    SortList d(0);
//    SortList e(5);
//    SortList f(7);
//    SortList g(2);
//    SortList h(3);
//    a.next=&b;
//    b.next=&c;
//    d.next=&e;
//    e.next=&f;
//    g.next=&h;
//    Solution solution;
//    vector<SortList *> node1;
//    node1.push_back(&a);
//    node1.push_back(&d);
//    node1.push_back(&g);
//    SortList *head=solution.mergeNLists(node1);
//    while(head){
//        cout<<head->data<<endl;
//        head=head->next;
//    }
//    return 0;
//}