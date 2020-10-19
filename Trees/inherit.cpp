#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct TreeNode{
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int data):data(data),left(nullptr),right(nullptr){}
  TreeNode(int data, TreeNode* left, TreeNode* right):data(data),left(left),right(right){}
};

class BinaryTreeOperations{
public:
  void printLevelOrder(TreeNode* root){
    if(root == nullptr)
      return;
    queue<TreeNode*> processQueue;
    processQueue.push(root);
    while(!processQueue.empty()){
      TreeNode* curr = processQueue.front();
      processQueue.pop();
      cout << curr->data << " ";
      if(curr->left != nullptr)
        processQueue.push(curr->left);
      if(curr->right != nullptr)
        processQueue.push(curr->right);
    }
  }
  void printLevelWise(TreeNode* root){
    if(root == nullptr)
      return;
    pair<TreeNode*, int> node;
    queue<pair<TreeNode*, int>> processQueue;
    map<int, vector<TreeNode*>> treeMap;
    int height  = 0;
    node = {root, height};
    processQueue.push(node);
    while(!processQueue.empty()){
      TreeNode* curr = processQueue.front().first;
      height = processQueue.front().second;
      treeMap[height].push_back(curr);
      processQueue.pop();
      if(curr->left != nullptr){
        node = {curr->left, height+1};
        processQueue.push(node);
      }
      if(curr->right != nullptr){
        node = {curr->right, height+1};
        processQueue.push(node);
      }
    }

    for(auto entry : treeMap){
      cout << entry.first << " -> ";
      for(auto value : entry.second){
        cout << value->data << ",";
      }
      cout << endl;
    }
  }
};

int main(){
  TreeNode* root = new TreeNode(2);
  root->left =  new TreeNode(3,new TreeNode(4),new TreeNode(6));
  root->right = new TreeNode(5, new TreeNode(7), new TreeNode(8));
  BinaryTreeOperations* bops = new BinaryTreeOperations();
  bops->printLevelWise(root);
  return 0;
}
