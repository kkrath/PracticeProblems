/* Diameter of a binary Tree */

#include<iostream>
using namespace std;

struct TreeNode{
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):value(x),left(NULL),right(NULL){}
};

TreeNode* getNewNode(int x){
	return new TreeNode(x);	
	}

class Solution{

	public:

		Solution(){
			/* do nothing - empty constructor */
		}

		int daimeterOfBT(TreeNode* root,int *height){

			if (root==NULL){
				*height = 0;
				return 0;
			}

			int lHeight = 0;
			int rHeight = 0;

			int lDiameter =  0; 
			int rDiameter =  0;

			*height = max(lHeight,rHeight) + 1;
			lDiameter = daimeterOfBT(root->left,&lHeight);
			rDiameter = daimeterOfBT(root->right,&rHeight);


			return max(lHeight+rHeight, max(lDiameter,rDiameter));

		}
	private:
		int heightOfBT(TreeNode* root){

		/** Heuristic 1: The longest length of a binary tree would be to find the 
		 *  distance between leaf node of left subtree and right subtree
		**/
		
		/* boundry condition */

		if(root == NULL)
			return 0;

		return max(heightOfBT(root->left),heightOfBT(root->right))+1;
		}
		

};

		
int main(){

	TreeNode* root = getNewNode(2);
	root->left = getNewNode(3);
	root->left->left = getNewNode(4);
	root->right = getNewNode(1);
	root->right->left = getNewNode(5);
	root->right->right = getNewNode(6);
	Solution* sol = new Solution();
	int *height = 0;
	cout << "Diameter of BT:" << sol->daimeterOfBT(root,height);
}