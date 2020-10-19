/* XOR Doubly Linked List */

#include<iostream>
using namespace std;

struct XORLinkedNode{
	int value;
	XORLinkedNode *both;
	XORLinkedNode(int x):value(x){}
};
class LinkedList{
private:
	XORLinkedNode *root  = nullptr;
	public:
		void addNode(int x){
			if(root == nullptr){
				root = new XORLinkedNode(x);
				root->both = 0;
			}else{
				XORLinkedNode *curr = root;
				XORLinkedNode *prev = 0;
				while(curr != nullptr){
					if(curr->both == prev)
						break;
					XORLinkedNode *next = (XORLinkedNode*) ((uintptr_t)curr->both ^ (uintptr_t)prev);
					prev = curr;
					curr = next;
				}
				XORLinkedNode* newNode = new XORLinkedNode(x);
				newNode->both = (XORLinkedNode*)((uintptr_t)curr ^ (uintptr_t)0);
				curr->both = (XORLinkedNode*)((uintptr_t)prev ^ (uintptr_t)newNode);
			}
		}
		bool find(int x){
			XORLinkedNode *curr = root;
			XORLinkedNode *prev = 0;
			while(curr != nullptr){
				if(curr->value == x)
					return true;
				XORLinkedNode *next = (XORLinkedNode*) ((uintptr_t)curr->both ^ (uintptr_t)prev);
				prev = curr;
				curr = next;
			}
			return false;
		}
};
int main(){
	LinkedList ls;
	ls.addNode(1);
	ls.addNode(2);
	ls.addNode(4);
	cout << (ls.find(4) ? "True":"False");
}