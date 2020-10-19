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


int findNumOfUniValTree(TreeNode* root){
    if(root == nullptr)
        return 0;
    if((root->left ? root->left->value == root->value : true) && (root->right ? root->right->value == root->value : true)){
        return 1 + findNumOfUniValTree(root->left) + findNumOfUniValTree(root->right);
    
    }else
        return findNumOfUniValTree(root->left) + findNumOfUniValTree(root->right);

}

int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(0, new TreeNode(1, new TreeNode(1), new TreeNode(1)), new TreeNode(0));
    cout << findNumOfUniValTree(root);
}