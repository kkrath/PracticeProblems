/* This program merges two sorted linked lists.
 * The definition of linked list is given by the 
 * following struct */
#include<iostream>
using namespace std;

struct LinkedNode{
	int data;
	LinkedNode* next;
	LinkedNode(int x):data(x),next(nullptr){}
};
void add(LinkedNode* root,int data){
	if(root == nullptr)
		root = new LinkedNode(data);
	else{
		LinkedNode* newNode = new LinkedNode(data);
		newNode->next = root;
		root = newNode;
	}
}

LinkedNode* mergeList(LinkedNode* a, LinkedNode* b){
	/* base cases */
	if(a == nullptr)
		return b;
	if(b == nullptr)
		return a;

	/* take a new list */
	LinkedNode* result = nullptr;
	if(a->data < b->data){
	result = a;
	result->next = mergeList(a->next,b);
	}else{
	result = b;
	result->next = mergeList(a,b->next);
	}
	return result;
}

int main(){
/* driver program */
LinkedNode* a = new LinkedNode(5);
add(a,3);
cout << a->data;
add(a,1);
cout << a->data;
LinkedNode* b = new LinkedNode(7);
add(b,6);
add(b,4);
add(b,2);
LinkedNode* res = mergeList(a, b);
while(res != nullptr){
	cout << res->data << "->";
	res = res->next;
}
cout<< "null" << endl;
}

