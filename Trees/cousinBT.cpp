/* binary tree level order traversal */


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

class BinaryTree{
private:
	queue<TreeNode*> q;

	int findLevel(TreeNode* root,TreeNode *node,int level){
		if(root == nullptr)
			return 0;
		if(root = node)
			return level;
		/* return level if node is present in left subtree */
		int l = findLevel(root->left,node,level+1);
		if( l != 0) return l;

		return findLevel(root->right,node,level+1);
	}


	int height(TreeNode* root){
		/* base condition */
		if(root == nullptr)
			return 0;
		int lheight = height(root->left);
		int rheight = height(root->right);

		return max(lheight,rheight)+1;
	}

	bool isSibling(TreeNode* root,TreeNode *node1, TreeNode *node2){
		/* base condition */
		if(root = NULL)
			return false;
		return ((root->left == node1 && root->right == node2) ||
				(root->left == node2 && root->right == node1) ||
				isSibling(root->left,node1,node2)			||
				isSibling(root->right,node1,node2));
	}
public:
	void levelOrderTraversal(TreeNode* root){
		/* base case */
		if(root == nullptr)
			return;
		/* enque the queue */
		q.push(root);
		while(!q.empty()){
			TreeNode * curr = q.front();
			q.pop();
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
			cout << curr->val<<",";
		}
	}
	bool isCousin(TreeNode *root,TreeNode *node1,TreeNode *node2){
		/* the two nodes node1 and node2 are only cousin when they both
		   are at the same level but are not siblings */
		int level1 = findLevel(root,node1,1);
		int level2 = findLevel(root,node2,1);
		bool res = isSibling(root,node1,node2);
		cout << level1 << " " << level2 <<  endl;
		cout << res << endl;
		return (level1 == level2) && !res;
	}

};
