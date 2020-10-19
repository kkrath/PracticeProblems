#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){}
    TreeNode(int data):data(data),left(NULL),right(NULL){}
    TreeNode(int data, TreeNode* left, TreeNode* right):data(data),left(left),right(right){}
};

class TreeOps{
    public:
        TreeNode* flatten(TreeNode* node){
            if(node == nullptr)
                return nullptr;
            TreeNode* left = nullptr;
            TreeNode* right =nullptr;
            if(node->left)
                left = flatten(node->left);
            if(node->right)
                right = flatten(node->right);
            TreeNode* temp = left;
            while(temp != nullptr && temp->right != nullptr)
                temp = temp->right;
            if(temp != nullptr){
                temp->right = right;
                node->right = left;
            }
            return node;
        }

};

int main(){
    TreeNode* root  = new TreeNode(1, new TreeNode(4, new TreeNode(5), new TreeNode(7)),new TreeNode(3, new TreeNode(2), new TreeNode(8)));
    TreeOps ops;
    root = ops.flatten(root);
    while(root != nullptr){
        cout << root->data << "->";
        root = root->right;
    }
    cout << "NULL" << endl;
}