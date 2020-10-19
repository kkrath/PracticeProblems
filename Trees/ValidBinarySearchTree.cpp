/* determine whether a tree is a valid binarySearchTree or not */

#include<iostream>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value): value(value),left(nullptr),right(nullptr){}
    TreeNode(int value,TreeNode* left,TreeNode* right): value(value),left(left),right(right){}
};

bool isValidBinaryTree(TreeNode* root){
    /* by defintion a tree is a binary search tree if all the left child are less than or equals to root
     and right children are greater than root*/
    if(root == nullptr)
        return true;
    if(isValidBinaryTree(root->left) && isValidBinaryTree(root->right))
        return (root->left != nullptr ? root->value >= root->left->value : true ) &&(root->right != nullptr ? root->value < root->right->value : true);
    else
        return false;
    
}

int main(){
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(4,new TreeNode(3), new TreeNode(5));
  root->right = new TreeNode(10, nullptr, new TreeNode(11));
  cout << isValidBinaryTree(root) << endl;
}