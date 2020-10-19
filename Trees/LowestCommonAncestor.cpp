#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):data(data),left(nullptr),right(nullptr){}
    TreeNode(int data, TreeNode* left, TreeNode* right):data(data),left(left),right(right){}
};
bool findpath(TreeNode* node, int n, vector<TreeNode*> &path);

void findLowestCommonAncestorOf(TreeNode* root,int n1, int n2){
    if(root == nullptr)
        return;
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;
    findpath(root,n1,path1);
    findpath(root,n2,path2);
    for(auto p: path1){
        cout << p->data << "->";
    }
    cout<< endl;
    for(auto p : path2){
         cout << p->data << "->";
    }
      cout<< endl;

}

bool findpath(TreeNode* node, int n, vector<TreeNode*> &path){
        if(node == nullptr)
            return false;

        if(node->data == n){
            return true;
        }
        path.push_back(node);
        if((node->left && findpath(node->left, n, path)) || 
            (node->right && findpath(node->right, n, path)))
            return true;

        path.pop_back();
        return false;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5, new TreeNode(4,new TreeNode(8),new TreeNode(7)),new TreeNode(6,new TreeNode(18),new TreeNode(13)));
    root->right = new TreeNode(15, new TreeNode(14,new TreeNode(17),new TreeNode(10)),new TreeNode(9,new TreeNode(2),new TreeNode(3)));
    findLowestCommonAncestorOf(root, 10, 5);
    return 0;
}