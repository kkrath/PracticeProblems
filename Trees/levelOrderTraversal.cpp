/* This program does a BFS or level order traversal of a binary tree */

#include<iostream>
#include<queue>
using namespace std;
class BinaryTreeNode{
public:
	int data;
	BinaryTreeNode *left,*right;
	BinaryTreeNode(int x){
		data = x;
		left = NULL;
		right = NULL;
	}

};

class Solution{
private:
	vector<int> binTreeArray;
public:
	vector<int> levelOrderTraversal(BinaryTreeNode* root){

		queue<BinaryTreeNode*> fifo;
		BinaryTreeNode* node = root;
		fifo.push(node);
		while(!fifo.empty()){
			BinaryTreeNode* temp = fifo.front();
			fifo.pop();
			if(temp->left)
				fifo.push(temp->left);
			if(temp->right)
				fifo.push(temp->right);
			binTreeArray.push_back(temp->data);
		}
		return binTreeArray;
	}
};

int main(){
	BinaryTreeNode *node = new BinaryTreeNode(2);
	node->left = new BinaryTreeNode(4);
	node->right = new BinaryTreeNode(7);
	node->left->left =  new BinaryTreeNode(8);
	node->left->right = new BinaryTreeNode(0);
	node->right->left = new BinaryTreeNode(3);
	node->right->right = new BinaryTreeNode(6);
	Solution *sol = new Solution();
	vector<int> V = sol->levelOrderTraversal(node);
	for(int v:V)
		cout <<  v << ",";
	cout<<endl;
}