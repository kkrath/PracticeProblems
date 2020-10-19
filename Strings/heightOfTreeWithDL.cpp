/* find the height of a tree whose leaf nodes are connected as a circular doubly linked list */

/* the left node and right node */
#include<iostream>
using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
	TreeNode(int x):data(x),left(NULL),right(NULL){}
};

class Solution{
public:
	Solution(){
		/* empty constructor */
	}
	int heightOfTree(TreeNode* root){
		/*base condition will be to check if it's a leaf node 
		* and the condition to check whether its a leaf node
		  is to check if the leaf node is part of circular 
		  doubly linked list */
		/* comparing two structs */
		if(root == NULL)
			return 0;
		if(root->left)
			if(root->left->right)
				if(root->left->right == root)
					return 1;
		return max(heightOfTree(root->left),heightOfTree(root->right)) + 1;
	}
};

int main(){

	TreeNode* root = new TreeNode(1);/* Level 0*/
	root->left = new TreeNode(2); /* Level 1 */
	root->right = new TreeNode(3); /* Level 1 */
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	//root->left->left->right = root->left->right;
	//root->left->right->left = root->left->left;

	Solution sol;
	cout << "Height of tree:" << sol.heightOfTree(root);
}