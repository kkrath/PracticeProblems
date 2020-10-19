/* Let's construct a binary tree from inorder and preorder */

#include<iostream>
#include<vector>
using namespace std;


class BinaryTreeNode{
public:
	int data;
	BinaryTreeNode *left, *right;
BinaryTreeNode(int x){
	data = x;
	left = NULL;
	right = NULL;
}

};

class Solution{

private:
	void inorder(BinaryTreeNode* root, vector<int> &inorderarr){
		if(root == NULL)
			return;
		inorder(root->left,inorderarr);
		inorderarr.push_back(root->data);
		inorder(root->right,inorderarr);

	}

	void preorder(BinaryTreeNode* root, vector<int> &preorderarr){
		if(root == NULL)
			return;
		preorderarr.push_back(root->data);
		preorder(root->left,preorderarr);
		preorder(root->right,preorderarr);
	}
	BinaryTreeNode* constructBT(vector<int>& inorder,vector<int> preorder,int iS,int iE,int pS,int pE){
		/* first element of preorder is root */
		/* base case */
		if(iS > iE)
			return NULL;

		/* recursive case */

		int rootVal = preorder[pS];
		int rootIdx = -1;
		for(int i = iS; i <= iE ; i++){
			if(inorder[i] == rootVal){
				rootIdx = i;
				break;
			}
		}
		/* lets compute new inorder for left and right subtree */
		int lInS = iS;
		int lInE = rootIdx - 1;
		int lPreS = pS + 1;
		int lPreE = lPreS + (lInE - lInS);
		/* right subTree */
		int rInS = rootIdx + 1;
		int rInE = iE;
		int rPreS = lPreE + 1;
		int rPreE = pE;
		BinaryTreeNode* root = new BinaryTreeNode(rootVal);
		root->left = constructBT(inorder,preorder,lInS,lInE,lPreS,lPreE);
		root->right = constructBT(inorder,preorder,rInS,rInE,rPreS,rPreE);
		return root;

	}
public:
	BinaryTreeNode* constructBT(vector<int>& inorder,vector<int>& preorder){
		return constructBT(inorder,preorder,0,inorder.size()-1,0,preorder.size()-1);
	}

	vector<int> inorder(BinaryTreeNode* root){
		vector<int> inorderarr;
		inorder(root,inorderarr);
		return inorderarr;

	}
	vector<int> preorder(BinaryTreeNode* root){
		vector<int> preorderarr;
		preorder(root,preorderarr);
		return preorderarr;

	}

	
};

int main(){
	BinaryTreeNode* root = new BinaryTreeNode(2);
	root->left = new BinaryTreeNode(4);
	root->right = new BinaryTreeNode(5);
	root->left->left =  new BinaryTreeNode(7);
	root->left->right = new BinaryTreeNode(8);
	root->right->right = new BinaryTreeNode(9);
	vector<int> vIn,vPre;
	Solution* sol = new Solution();
	vIn = sol->inorder(root);
	for(int v:vIn)
		cout << v << "," ;
	cout<<endl;

	vPre = sol->preorder(root);
	for(int v:vPre)
		cout << v << "," ;
	cout<<endl;

	BinaryTreeNode* newRoot = sol->constructBT(vIn,vPre);
	vector<int> newRootIn = sol->inorder(newRoot);
	vector<int> newRootPre = sol->preorder(newRoot);
	for(int v:newRootIn)
		cout<<v<<",";
	cout<<endl;
	for(int v:newRootPre)
		cout<<v<<",";
	cout<<endl;

}

