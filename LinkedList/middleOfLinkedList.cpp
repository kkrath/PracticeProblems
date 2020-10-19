/* finding the middle of a linked list */

/* we will take two poineters starting from head and move one pointer gradually over each node, while moving other every second step the first pointer make this way we will reach the middle of the list */

#include<iostream>
using namespace std;

typedef struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL){}
}ListNode;
class Solution{
	
public:
	int middleNode(ListNode* node){
		ListNode* fast_p = node;
		ListNode* slow_p = node;
		int count = 0;
		while(fast_p != NULL){
			count++;
			fast_p = fast_p->next;
		if(count % 2 == 0)
			slow_p = slow_p->next;
		}
	return slow_p->val;
}

ListNode* getNewNode(int val){
	ListNode* newNode = new ListNode(val);
	return newNode;
}
};

	
int main(){
	Solution sol;
	ListNode* head = sol.getNewNode(2);
	head->next = sol.getNewNode(4);
	head->next->next = sol.getNewNode(8);
	head->next->next->next = sol.getNewNode(9);
	head->next->next->next->next =  sol.getNewNode(11);
	cout << sol.middleNode(head);

}