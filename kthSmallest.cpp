/* find the kth smallest number in an Binary Search Tree */


/* first we will find the in order traversal of the BST which can be done in O(n) 
   time complexity and O(n) space complexity. Then we will find out the kth number from
   left in O(1) and O(n) space complexity */

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
 };
class Solution {
private:
	vector<int> inordr;
	/* find the inorder of BST using depth first search */
	void inorder(TreeNode* root){
		if(root == nullptr)
			return;
		inorder(root->left);
		inordr.push_back(root->val);
		inorder(root->right);
	}
public:
    int kthSmallest(TreeNode* root, int k) {
    	/* find the inorder traversal of the tree first */
    	inorder(root);

    	/* now we will look for the kth element as the inorder array will be sorted */
		return k <= inordr.size() ? inordr[k-1] :  -1;        
    }
};

int main(){
	TreeNode* root = new TreeNode(3,new TreeNode(1,nullptr,new TreeNode(2)),new TreeNode(4));
	Solution sol;
	cout << sol.kthSmallest(root,5) << endl;
}