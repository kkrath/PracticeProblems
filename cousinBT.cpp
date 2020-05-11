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

	int height(TreeNode* root){
		/* base condition */
		if(root == nullptr)
			return 0;
		lheight = height(root->left);
		rheight = height(root->right);

		return max(lheight,rheight)+1;
	}
};
int main(){
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4,new TreeNode(6),nullptr);
	root->right = new TreeNode(3,new TreeNode(11),new TreeNode(8));
	BinaryTree bt;
	bt.levelOrderTraversal(root);

}