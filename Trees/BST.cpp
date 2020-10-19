/**/

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

/* find the largest BST in a given binary tree */

int findLargetsBst(TreeNode* root){
    if(root == nullptr)
        return 0;
    
}