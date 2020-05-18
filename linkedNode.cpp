
#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    	ListNode* odd = head;
    	ListNode* even = head->next;
    	ListNode* connectNode = head->next;
    	while( odd != nullptr  &&  even != nullptr ){
    		ListNode* t = even->next;
    		if( t ==  nullptr)
    			break;
    		odd->next = even->next;
    		odd = odd->next;
    		even->next = odd->next;
    		even = even->next;
    	}
    	/* join the connect node to end of odd node */
    	odd->next = connectNode;
    	return head;
    }
};

int main(){
	ListNode* head = new ListNode(5);
	head->next = new ListNode(2);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(3);
	Solution sol;
	head = sol.oddEvenList(head);
	while(head != nullptr){
		cout << head->val << " " ;
		head = head->next;
	}
}