
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
private:
	queue<TreeNode*> q;
	int findLevel(TreeNode* root,int node,int level){
		if(root == nullptr)
			return 0;
		if(root->val == node)
			return level;
		/* return level if node is present in left subtree */
		int l = findLevel(root->left,node,level+1);
		if( l != 0) return l;

		return findLevel(root->right,node,level+1);
	}
	bool isSibling(TreeNode* root,int node1,int node2){
		/* base condition */
		if(root == NULL)
			return false;
		if(root->left && root->right)
			bool res1 = (root->left->val == node1 && root->right->val == node2) ||
				(root->left->val == node2 && root->right->val == node1);
		return res1 || isSibling(root->left,node1,node2) || isSibling(root->right,node1,node2);
	}
public:
	bool isCousins(TreeNode *root,int node1,int node2){
		/* the two nodes node1 and node2 are only cousin when they both
		   are at the same level but are not siblings */
		 return (findLevel(root,node1,1) == findLevel(root,node2,1)) && !isSibling(root,node1,node2);

	}

};
int main(){
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4,new TreeNode(6),nullptr);
	root->right = new TreeNode(3,nullptr,new TreeNode(8));
	Solution bt;
	//bt.levelOrderTraversal(root);
	//cout << "are they cousin ? ";
	cout << bt.isCousins(root,6,8);
}