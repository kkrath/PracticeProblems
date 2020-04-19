/* Diameter of a binary Tree */

#include<iostream>
#include<utility>
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

		int daimeterOfBT(TreeNode* root){

			if (root==NULL)
				return 0;

			int lHeight = heightOfBT(root->left);
			int rHeight = heightOfBT(root->right);

			int lDiameter =  daimeterOfBT(root->left);
			int rDiameter =  daimeterOfBT(root->right);

			return max(lHeight+rHeight, max(lDiameter,rDiameter));


		}

		int diameterOfBTOpt(TreeNode* root){

			return diameterHt(root).first;
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

		pair<int,int> diameterHt(TreeNode* node){

			if(node == NULL){
				return{0,0};
			}
			pair<int,int> left = diameterHt(node->left);
			pair<int,int> right = diameterHt(node->right);
			int diameter = max({left.second+right.secnd,left.first,right.first});
			return {diameter,max(left.second,right.second)+1};
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
	cout << "Diameter of BT:" << sol->daimeterOfBT(root);
	cout << "Diameter of BT:" << sol->diameterOfBTOpt(root);
}