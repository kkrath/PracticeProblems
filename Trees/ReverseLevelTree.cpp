#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<stack>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value): value(value),left(nullptr),right(nullptr){}
    TreeNode(int value,TreeNode* left,TreeNode* right): value(value),left(left),right(right){}
};


void printTreeReverseLevel(TreeNode* root){
    if(root == nullptr)
        return;
    stack<int> st;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* curr = que.front();que.pop();
        st.push(curr->value);
        if(curr->right)
            que.push(curr->right);
        if(curr->left)
            que.push(curr->left);
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2,new TreeNode(4),new TreeNode(8));
    root->right = new TreeNode(6, new TreeNode(8), new TreeNode(3));
    printTreeReverseLevel(root);
}