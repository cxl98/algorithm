////
//// Created by cxl on 19-9-12.
////
//#include <iostream>
//#include <set>
//using namespace std;
//typedef int Status;
//struct ListNOde{
//    Status val;
//    ListNOde *next;
//    ListNOde(Status x) :val(x),next(NULL) {}//构造器
//};
//int get_list_length(ListNOde *head){
//    int len=0;
//    while(head){
//        len++;
//        head=head->next;
//    }
//    return len;
//}
//
//ListNOde *forward_long_list(int long_len,int short_len,ListNOde *head){
//    int delta=long_len-short_len;
//    while(head && delta){
//        head=head->next;
//        delta--;
//    }
//    return head;
//}
//class Solution{
//public:
//    ListNOde *reverseList(ListNOde *head){
//        ListNOde *new_head=NULL;
//        while(head){
//         ListNOde *next=head->next;//备份head->next
//         head->next=new_head;//更新head->next
//         new_head=head;//移动nwe_head
//         head=next;//遍历链表
//        }
//        return new_head;//返回新链表头节点
//    }
//
//    ListNOde *reverseBetween(ListNOde *head,int m,int n){
//        int change_len=n-m+1;//计算需要逆置节点的个数
//        ListNOde *pre_head=NULL;//初始化开始逆置节点的前驱
//        ListNOde *resuit=head;//最终转换后的链表头节点,非特殊情况就是head
//        while(head && --m){//将head向前移动m-1个位置
//            pre_head=head;//记录head的前驱
//            head=head->next;
//        }
//        ListNOde *modify_list_tail=head;//将modify_list_tail指向当前的head,即逆置后的链表尾
//        ListNOde *new_head=NULL;
//        while(head && change_len){
//            ListNOde *next=head->next;
//            head->next=new_head;
//            new_head=head;
//            head=next;
//            change_len--;//每完成一个节点change_len减1
//        }
//        modify_list_tail->next=head;//连接逆置后的链表尾与逆置段的后一个节点
//
//
//        if (pre_head){//如果pre_head不空.说明不是从第一个节点开始逆置的m>1
//            pre_head->next=new_head;//将逆置链表开始的节点的前驱与逆置后的头节点连接
//        }else{
//            resuit=new_head;//如果pre_head为空,说明m==1从第一个节点开始逆置,返回head
//        }
//        return resuit;
//    }
//    //思路1=========================
//    //例2:求两个链表的交点
//    ListNOde *getIntersectionNode(ListNOde *headA,ListNOde *headB){
//        set<ListNOde *> listNode;
//        while(headA){
//            listNode.insert(headA);
//            headA=headA->next;//遍历链表A
//        }
//        while(headB){
//            if (listNode.find(headB)!=listNode.end()){
//                return headB;
//            }
//            headB=headB->next;//遍历链表B
//        }
//        return NULL;
//    }
//    //思路2============================
//    ListNOde *getIntersectionNode1(ListNOde *headA,ListNOde *headB){
//        int list_A_len=get_list_length(headA);
//        int list_B_len=get_list_length(headB);
//        if (list_A_len>list_B_len){
//            headA=forward_long_list(list_A_len,list_B_len,headA);
//        } else{
//            headB=forward_long_list(list_B_len,list_A_len,headB);
//        }
//        while(headA && headB){
//            if (headA==headB){
//                return headA;
//            }
//            headA=headA->next;
//            headB=headB->next;
//        }
//        return NULL;
//
//    }
//
//    //===============例3:链表求环=================
//    //思路1
//    ListNOde *detectCycle(ListNOde *head){
//        set<ListNOde *> listNode;
//        while(head){
//            if (listNode.find(head)!=listNode.end()){
//                return head;
//            }
//            listNode.insert(head);
//            head=head->next;
//        }
//        return NULL;
//    }
//    //思路2
//    ListNOde *detectCycle1(ListNOde *head){
//        ListNOde *slow=head;
//        ListNOde *fast=head;
//        ListNOde *meet=NULL;
//        while(fast){
//            slow=slow->next;
//            fast=fast->next;
//            if(!fast){
//              return NULL;
//            }
//            fast=fast->next;
//            if(fast==slow){
//                meet=fast;
//                break;
//            }
//        }
//        if(meet==NULL){
//            return NULL;
//        }
//        while(head && meet){
//            if(meet==head){
//                return head;
//            }
//            head=head->next;
//            meet=meet->next;
//        }
//        return NULL;
//    }
//    //=========例题4:链表的划分======
//    ListNOde *partition(ListNOde *head,int x){
//        ListNOde less_head(0);
//        ListNOde more_head(0);
//        ListNOde *less_ptr=&less_head;
//        ListNOde *more_ptr=&more_head;
//        while(head){
//            if (head->val<x){
//                less_ptr->next=head;
//                less_ptr=head;
//            }else{
//                more_ptr->next=head;
//                more_ptr=head;
//            }
//            head=head->next;
//        }
//        less_ptr->next=more_head.next;
//        more_ptr->next=NULL;
//        return less_head.next;
//    }
//
//};
//int main(){
////    ListNOde a(1);
////    ListNOde b(2);
////    ListNOde c(3);
////    ListNOde d(4);
////    ListNOde e(5);
////    a.next=&b;
////    b.next=&c;
////    c.next=&d;
////    d.next=&e;
////    Solution solution;
////    ListNOde *head=&a;
////    while(head){
////        cout<<head->val<<endl;
////        head=head->next;
////    }
////    cout<<"reverse "<<endl;
////    head=solution.reverseList(&a);
////    while(head){
////        cout<<head->val<<endl;
////        head=head->next;
////    }
////    ListNOde *head=solution.reverseBetween(&a,2,4);
////    while(head){
////        cout<<head->val<<endl;
////        head=head->next;
////    }
////
//
//    //==================求交集========================
//
////    set<int> aa;
////    const  int A_len=7;
////    const  int B_len=8;
////    int a1[A_len]={5,1,4,8,10,1,3};
////    int b1[B_len]={2,7,6,3,1,6,0,1};
////    for (int i = 0; i <A_len ; ++i) {
////        aa.insert(a1[i]);
////    }
////    for (int j = 0; j <B_len ; ++j) {
////        if (aa.find(b1[j])!=aa.end()){
////            cout<<"b1["<<j<<"]"<<"="<<b1[j]<<endl;
////        }
////    }
////    ListNOde a1(1);
////    ListNOde a2(2);
////    ListNOde b1(3);
////    ListNOde b2(4);
////    ListNOde b3(5);
////    ListNOde c1(6);
////    ListNOde c2(7);
////    ListNOde c3(8);
////    a1.next=&a2;
////    a2.next=&c1;
////    c1.next=&c2;
////    c2.next=&c3;
////    b1.next=&b2;
////    b2.next=&b3;
////    b3.next=&c1;
////    Solution solution;
////
////    ListNOde *result=solution.getIntersectionNode1(&a1,&b1);
////    cout<<result->val<<endl;
//
//    //===============求环====================
////
////    ListNOde a(1);
////    ListNOde b(2);
////    ListNOde c(3);
////    ListNOde d(4);
////    ListNOde e(5);
////    ListNOde f(6);
////    ListNOde g(7);
////    a.next=&b;
////    b.next=&c;
////    c.next=&d;
////    d.next=&e;
////    e.next=&f;
////    f.next=&g;
////    g.next=&c;
////    Solution solution;
////
////    ListNOde *node=solution.detectCycle1(&a);
////    if (node){
////        cout<<node->val<<endl;
////    }
//    //========链表的划分=======
//    ListNOde a(1);
//    ListNOde b(4);
//    ListNOde c(3);
//    ListNOde d(2);
//    ListNOde e(5);
//    ListNOde f(2);
//    a.next=&b;
//    b.next=&c;
//    c.next=&d;
//    d.next=&e;
//    e.next=&f;
//    Solution solution;
//    ListNOde *head=solution.partition(&a,3);
//    while(head){
//        cout<<head->val;
//        head=head->next;
//        if (head!= nullptr){
//        cout<<"-->";
//        }
//    }
//    return 0;
//}