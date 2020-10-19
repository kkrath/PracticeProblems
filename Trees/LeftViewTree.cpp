#include<iostream>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value, TreeNode* left, TreeNode* right):value(value),left(left),right(right){}
    TreeNode(int value):value(value),left(nullptr),right(nullptr){}
};


void printLeftView(TreeNode* root){
    if(root == nullptr)
        return;
    cout << root->value << " ";
    if(root->left)
        printLeftView(root->left);
    else
        printLeftView(root->right);
    return;
}

bool isBST(TreeNode* root){
    if(root == nullptr)
        true;
    return (root->left ? root->left->value < root->value : true) && (root->right ? root->right->value > root->value : true)
    && isBST(root->left) && isBST(root->right);

}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(6, nullptr,new TreeNode(8)), new TreeNode(7));
    root->right = new TreeNode(3, new TreeNode(4), new TreeNode(5));
    printLeftView(root);
}