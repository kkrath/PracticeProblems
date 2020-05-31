/* we will write a program to create a binary tree from a preorder traversl */
#include<iostream>
#include<vector>
using namespace std;

typedef struct TreeNode{
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):value(x),left(nullptr),right(nullptr){}
}TreeNode ;

TreeNode* getNewTreeNode(int x){
	TreeNode* newNode = new TreeNode(x);
	return newNode;
}

#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
	TreeNode* constructBinaryTree(vector<int> &preorder,int start,int end){
		if(end - start < 0)
			return nullptr;
		if(start == end)
			/* we have reached leaf node */
			return getNewTreeNode(preorder[start]);
		//cout << start << " " << end << " ";
		int rootIdx = start;
		int id = rootIdx + 1;
		while(preorder[id] < preorder[rootIdx] && id <= end)
			id++;
		int lpS = -1;
		int rpS = -1;
		int rpE = -1;
		int lpE = -1;
		if(id > 0){
			/*left subtree exists*/
			lpS = rootIdx+1;
			lpE = id-1;
			rpS = id;
			rpE = end;
		}else{
			lpS = 0;
			lpE = lpS + 1;
			rpS = rootIdx+1;
			rpE = end;
		}
		//cout << lpS << " " << lpE << " " << rpS << " " << rpE<< endl;
		TreeNode* root = getNewTreeNode(preorder[rootIdx]);
		root->left = constructBinaryTree(preorder,lpS,lpE);
		root->right = 	constructBinaryTree(preorder,rpS,rpE);
		return root;
}

public:
	TreeNode* restoreBinaryTree(vector<int> &preorder){
		return constructBinaryTree(preorder,0,preorder.size()-1);
	}

	TreeNode* restoreBinaryTreeRecursive(vector<int> &preorder){
		if(preorder.empty())
			return nullptr;
		int n  = preorder.size();
		vector<int> left,right;
		int root_val = preorder[0];
		for(int i = 1;i < n;i++){
			if(preorder[i] < root_val)
				left.push_back(preorder[i]);
			else
				right.push_back(preordr[i]);	
		}
		TreeNode* root = new TreeNode(root_val);
		root->left = restoreBinaryTreeRecursive(left);
		root->right = restoreBinaryTreeRecursive(right);
		return root;
	}



};
void Preorder(TreeNode* root){
		if(root == nullptr)
			return;
		cout << root->value << ",";
		Preorder(root->left);
		Preorder(root->right);
	}
int main(){
	Solution *sol =  new Solution();
	vector<int> preorder{4,2};
	TreeNode* root = sol->restoreBinaryTree(preorder);
	Preorder(root);
	cout<< endl;
	
}
