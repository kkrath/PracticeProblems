#include<iostream>
using namespace std;


struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):data(data),left(nullptr),right(nullptr){}
    TreeNode(int data, TreeNode* left, TreeNode* right):data(data),left(left),right(right){}
};

/* this program aims to find the maximum sum path 
from node n1 to any given node n2 */

int findMaxSumPath(TreeNode* node, int &globalmax){
    if(node == nullptr)
        return 0;

    int left = findMaxSumPath(node->left, globalmax);
    int right = findMaxSumPath(node->right, globalmax);

    int returnmax = max(max(left, right) + node->data, node->data);

    int maxvalue  = max(returnmax, left + right + node->data);

    if(maxvalue > globalmax)
        globalmax = maxvalue;

    return maxvalue;
}


int findmax(TreeNode* root){
    int globalmax = INT_MIN;
    return findMaxSumPath(root, globalmax);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3, new TreeNode(5), new TreeNode(-9));
    root->right = new TreeNode(7, new TreeNode(-4), new TreeNode(6));
    cout << findmax(root);
}