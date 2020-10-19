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

void inorder(TreeNode* root){
    if(root == nullptr)
        return;
    inorder(root->left);
    cout << root->value << " " ;
    inorder(root->right);
}

void invertBinaryTree(TreeNode* root){
    if(root == nullptr)
        return;
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    return;
}

void levelOrderTraversal(TreeNode* root){
    if(root == nullptr)
        return;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();que.pop();
        cout << temp->value << " ";
        if(temp->left != nullptr)
            que.push(temp->left);
        if(temp->right != nullptr)
            que.push(temp->right);
    }
    cout <<  endl;
}

void printVerticalLevel(TreeNode* root, int level, int width){
    if(root == nullptr)
        return;
        // if this node is on the given vertical level print it
    if(level == width)
        cout << root->value << " ";
    
    printVerticalLevel(root->left,level, width-1);
    printVerticalLevel(root->right,level, width+1);
    
}
void findMinAndMaxWidth(TreeNode* root, int* min, int* max, int width){
    if(root == nullptr)
        return;
    
    if(width < *min)
        *min = width;
    else if(width > *max)
        *max = width;
    findMinAndMaxWidth(root->left, min, max, width - 1);
    findMinAndMaxWidth(root->right, min, max, width + 1);   
}

void vertcalOrderTraversal(TreeNode* root){
    if(root == nullptr)
        return;
    int min  = 0 , max  = 0;
    findMinAndMaxWidth(root, &min, &max, 0);

    for(int i = min; i <= max; i++){
        printVerticalLevel(root,i,0);
        cout << endl;
    }
    
}

void findWidth(TreeNode* root, int width, map<int, vector<int>> &map){
        if(root == nullptr)
            return;
        map[width].push_back(root->value);
        findWidth(root->left, width - 1, map);
        findWidth(root->right, width + 1, map);
}

void verticalTraversal(TreeNode* root){
    map<int, vector<int>> map;
    int width = 0;
    findWidth(root, width, map);
    for(auto i : map){
        vector<int> temp = i.second;
        for(auto c: temp)
            cout << c << " ";
        cout <<  endl;
    }
}

void inorderItr(TreeNode* root){
    if(!root)
        return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* temp = st.top();st.pop();
        if(temp->right != nullptr)
                st.push(temp->right);
        if(temp->left != nullptr)
                st.push(temp->left);
    }
    while(!st.empty()){
        cout << st.top()->value << " ";
        st.pop();
    }

}

void verticalLevelOrderTraversal(TreeNode* root){

    if(root == nullptr)
        return;
    map<int,vector<int>> map;
    int width  = 0;

    queue<pair<TreeNode*, int>> que;
    que.push(make_pair(root, width));

    while(!que.empty()){
        pair<TreeNode*, int> temp = que.front();
        que.pop();
        width = temp.second;
        TreeNode* node = temp.first;
        map[width].push_back(node->value);
        if (node->left != nullptr)
            que.push(make_pair(node->left, width - 1));
        if(node->right != nullptr)
            que.push(make_pair(node->right, width + 1));
    }
    for(auto m : map){
        vector<int> vec = m.second;
        for(auto v: vec)
            cout << v << " ";
        cout << endl;
    }

}


int main(){
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(4,new TreeNode(6), new TreeNode(9));
  root->right = new TreeNode(5, new TreeNode(2), new TreeNode(8));
//   inorder(root);
//   cout << endl;
//   levelOrderTraversal(root);
//   cout << endl;
//   invertBinaryTree(root);
//   inorder(root);
//   cout << endl;
//   levelOrderTraversal(root);
//   cout << endl;
  vertcalOrderTraversal(root);
  cout << endl;
  verticalTraversal(root);
  cout << endl;
  verticalLevelOrderTraversal(root);
  cout << endl;
  inorderItr(root);
  cout << endl;

}