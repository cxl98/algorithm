//
// Created by cxl on 19-9-25.
//

#include <iostream>
#include <vector>
#include <search.h>
#include <queue>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x),left(NULL),right(NULL){}
};
///**
// *前序遍历
// * @param node 正在遍历的节点
// * @param layer  当前节点的层数
// */
//void preorder_print(TreeNode *node,int layer){
//    if (!node){ return;}
//    for (int i = 0; i <layer ; ++i) {
//        cout<<"-----";//根据层数打印相应的"-"
//    }
//    cout<<node->val<<endl;
//    preorder_print(node->left,layer+1);//遍历左子树,层数加1
//    preorder_print(node->right,layer+1);//遍历右子树,层数加1
//}
///**
// * 中序遍历
// * @param node
// * @param layer
// */
//void preorder_print1(TreeNode *node,int layer){
//    if(!node) return ;
//    preorder_print1(node->left,layer+1);
//    for (int i = 0; i <layer ; ++i) {
//        cout<<"-----";//根据层数打印相应的"-"
//    }
//    cout<<node->val<<endl;
//    preorder_print1(node->right,layer+1);
//}
///**
// * 后序遍历
// * @param node
// * @param layer
// */
//void preorder_print2(TreeNode *node,int layer){
//    if (!node) return;
//    preorder_print2(node->left,layer+1);
//    preorder_print2(node->right,layer+1);
//    for (int i = 0; i <layer ; ++i) {
//        cout<<"-----";//根据层数打印相应的"-"
//    }
//    cout<<node->val<<endl;
//}
//int main(){
//    TreeNode a(1);
//    TreeNode b(2);
//    TreeNode c(5);
//    TreeNode d(3);
//    TreeNode e(4);
//    TreeNode f(6);
//    a.left=&b;
//    a.right=&c;
//    b.left=&d;
//    b.right=&e;
//    c.right=&f;
//    preorder_print2(&a,0);
//    return 0;
//}



//例题1:路径之和
//class Solution{
//public:
//    vector<vector<int>> pathSum(TreeNode *root,int sum){
//        vector<vector<int>> result;
//        vector<int> path;
//        int path_value=0;
//        preorder(root,path_value,sum,path,result);
//        return result;
//    }
//private:
//    void preorder(TreeNode *node,int &path_value,int sum,vector<int> &path,vector<vector<int>> &result){
//        if (!node) {return;}
//        path_value+=node->val;
//        path.push_back(node->val);
//        if (!node->left&&!node->right&&path_value==sum){
//            result.push_back(path);
//        }
//        preorder(node->left,path_value,sum,path,result);
//        preorder(node->right,path_value,sum,path,result);
//        path_value-=node->val;
//        path.pop_back();
//
//    }
//};
//int main(){
//    TreeNode a(5);
//    TreeNode b(4);
//    TreeNode c(11);
//    TreeNode d(7);
//    TreeNode e(2);
//    TreeNode f(8);
//    TreeNode g(13);
//    TreeNode h(4);
//    TreeNode i(5);
//    TreeNode j(1);
//    a.left=&b;
//    b.left=&c;
//    c.left=&d;
//    c.right=&e;
//    a.right=&f;
//    f.left=&g;
//    f.right=&h;
//    h.left=&i;
//    h.right=&j;
//    Solution solution;
//    vector<vector<int>> result=solution.pathSum(&a, 22);
//    for (int k = 0; k < result.size(); ++k) {
//        for (int l = 0; l <result[k].size(); ++l) {
//            cout<<"["<<result[k][l]<<"]";
//        }
//        cout<<"\n";
//    }
//}

/**
 *
 * @param node 正在遍历的节点
 * @param search //待搜索的节点
 * @param path //遍历时节点的路径栈
 * @param result 最终搜索到节点的结果
 * @param finsh 记录是否找到节点的search的变量,未找到为0,否则为1
 * //例题2:最近公共节点
 */
////求根节点至某节点路径
//void perorder(TreeNode *node, TreeNode *search,vector<TreeNode *>&path,vector<TreeNode*>&result,int &finish){
//
//    if (!node||finish){
//        return;
//    }
//    path.push_back(node);//先序遍历时,将节点压栈
//
//    if (node==search){
//        finish=1;
//        result=path;
//    }
//    perorder(node->left,search,path,result,finish);
//    perorder(node->right,search,path,result,finish);
//    path.pop_back();
//}
//////求两路径上最后一个相同的节点
//
//class Solution{
//public:
//    TreeNode *lowestCommonAncestor(TreeNode *root,TreeNode * p,TreeNode *q){
//        vector<TreeNode *> path;
//        vector<TreeNode *> node_p_path;
//        vector<TreeNode *> node_q_path;
//        int finish=0;
//
//        perorder(root,p,path,node_p_path,finish);
//        path.clear();
//        finish=0;
//        perorder(root,q,path,node_q_path,finish);
//        int path_len=0;
//        if (node_p_path.size()<node_q_path.size()){
//            path_len=node_p_path.size();
//        }else{
//            path_len=node_q_path.size();
//        }
//        TreeNode *result=0;
//        for (int i = 0; i <path_len ; ++i) {
//            if (node_p_path[i]==node_q_path[i]){
//                result=node_p_path[i];
//            }
//        }
//        return result;
//    }
//};
//int main(){
//    TreeNode a(3);
//    TreeNode b(5);
//    TreeNode c(1);
//    TreeNode d(6);
//    TreeNode e(2);
//    TreeNode f(0);
//    TreeNode x(8);
//    TreeNode y(7);
//    TreeNode z(4);
//    a.left=&b;
//    a.right=&c;
//    b.left=&d;
//    b.right=&e;
//    c.left=&f;
//    c.right=&x;
//    e.left=&y;
//    e.right=&z;
//    Solution solution;
//    TreeNode *reslut=solution.lowestCommonAncestor(&a,&b,&f);
//    cout<<"lowestCommonAncestor="<<reslut->val<<endl;
//    reslut=solution.lowestCommonAncestor(&a,&d,&z);
//    cout<<"lowestCommonAncestor="<<reslut->val<<endl;
//    reslut=solution.lowestCommonAncestor(&a,&b,&y);
//    cout<<"lowestCommonAncestor="<<reslut->val<<endl;
//    return 0;
//}





////例题3:二叉树转链表
//给定一个二叉树,将该二叉树就地转换为单链表.单链表中节点顺序为二叉树前序遍历顺序

//方法1
//class Solution{
//    //方法1
//public:
//    void flaten(TreeNode *root){
//        vector<TreeNode *> node_vec;
//        preorder(root,node_vec);
//        for (int i = 0; i <node_vec.size() ; ++i) {
//            node_vec[i-1]->left=NULL;
//            node_vec[i-1]->right=node_vec[i];
//        }
//    }
//
//
//    void flaten1(TreeNode *root){
//        TreeNode *last=NULL;
//        preorder1(root,last);
//    }
//private:
//    void preorder(TreeNode *node,vector<TreeNode *> &node_vec){
//        if (!node){
//            return;
//        }
//        node_vec.push_back(node);
//        preorder(node->left,node_vec);
//        preorder(node->right,node_vec);
//    }
//
//
//
//    //方法2
//    void preorder1(TreeNode *node,TreeNode *&last){
//        if (!node) return;
//        if (!node->left&&!node->right){
//            last=node;
//            return;
//        }
//
//        TreeNode *left=node->left;
//        TreeNode *right=node->right;
//        TreeNode *last_left=NULL;
//        TreeNode *last_right=NULL;
//
//        if (left){
//            preorder1(left,last_left);
//                node->left=NULL;
//                node->right=left;
//                last=last_left;
//
//        }
//        if (right){
//            preorder1(right,last_right);
//            if (last_left){
//                last_left->right=right;
//            }
//            last=last_right;
//        }
//    }
//};
//int main(){
//    TreeNode a(1);
//    TreeNode b(2);
//    TreeNode c(3);
//    TreeNode d(4);
//    TreeNode e(5);
//    TreeNode f(6);
//    a.left=&b;
//    a.right=&e;
//    b.left=&c;
//    b.right=&d;
//    e.right=&f;
//    Solution solution;
//    solution.flaten1(&a);
//    TreeNode *head=&a;
//    while(head){
//        if (head->left){
//            cout<<"ERROR"<<endl;
//        }
//        cout<<head->val;
//        head=head->right;
//    }
//    cout<<endl;
//    return 0;
//}



//例题4:侧面观察二叉树
//二叉树的层次遍历
//void BFS_print(TreeNode *root){
//    queue<TreeNode *> Q;
//    Q.push(root);
//    while (!Q.empty()){
//        TreeNode *node =Q.front();
//        Q.pop();
//        cout<<node->val<<endl;
//        if (node->left){
//            Q.push(node->left);
//        }
//        if (node->right){
//            Q.push(node->right);
//        }
//    }
//}
//
//int main(){
//    TreeNode a(1);
//    TreeNode b(2);
//    TreeNode c(5);
//    TreeNode d(3);
//    TreeNode e(4);
//    TreeNode f(6);
//    a.left=&b;
//    a.right=&c;
//    b.left=&d;
//    b.right=&e;
//    c.right=&f;
//    BFS_print(&a);
//    return 0;
//}

//class Solution{
//public:
//    vector<int > rigthSideView(TreeNode *root){
//        vector<int> view;//按层遍历的最后一个节点
//        queue<pair<TreeNode *,int >> Q;
//
//        if (root){
//            Q.push(make_pair(root,0));
//        }
//
//        while(!Q.empty()){
//            TreeNode *node=Q.front().first;//搜索节点
//            int depth=Q.front().second;//待搜索节点的层数
//            Q.pop();
//            if (view.size()==depth){
//                view.push_back(node->val);
//            } else{
//                view[depth]=node->val;
//            }
//            if (node->left){
//                Q.push(make_pair(node->left,depth+1));
//            }
//            if(node->right){
//                Q.push(make_pair(node->right,depth+1));
//            }
//        }
//    return view;
//    }
// };
//
//int main(){
//    TreeNode a(1);
//    TreeNode b(2);
//    TreeNode c(5);
//    TreeNode d(3);
//    TreeNode e(4);
//    TreeNode f(6);
//    a.left=&b;
//    a.right=&c;
//    b.left=&d;
//    b.right=&e;
//    c.right=&f;
//    Solution solution;
//    vector<int> xxx=solution.rigthSideView(&a);
//    for (int i = 0; i < xxx.size(); ++i) {
//        cout<<xxx[i]<<endl;
//    }
//}

