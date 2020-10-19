/*segregate a linked list*/
#include<iostream>
using namespace std;
struct ListNode{
    int value;
    ListNode* next;
    ListNode(int value):value(value),next(nullptr){}
};

ListNode* reverse(ListNode* head){
    /* without using stack */
    /* base case */
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode* node = nullptr;
    ListNode* probe  = head;
    ListNode* first = node;
    while(probe != nullptr){
        ListNode* curr = probe;
        probe = probe->next;
        curr->next = first;
        first = curr;        
    }
    
    head = first;
    return head;
}

ListNode* segregateList(ListNode* head){

    ListNode* zeroNode = new ListNode(0);
    ListNode* oneNode = new ListNode(0);
    ListNode* twoNode =  new ListNode(0);

    ListNode* zero = zeroNode;
    ListNode* one = oneNode;
    ListNode* two = twoNode;

    ListNode* probe = head;
    while(probe != nullptr){
        if(probe->value == 0){
            zero->next = probe;
            zero = zero->next;
            probe = probe->next;
        }else if(probe->value == 1){
            one->next = probe;
            one = one->next;
            probe = probe->next;
        }else{
            two->next = probe;
            two = two->next;
            probe = probe->next;
        }
    }
    zero->next = (oneNode->next) ? (oneNode->next) :  (twoNode->next);
    one->next = twoNode->next;
    two->next = nullptr;
    head = zeroNode->next;

    delete zeroNode;
    delete oneNode;
    delete twoNode;

    return head;

}


int main(){
    ListNode* head = new ListNode(1);
    head->next =  new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(1);

    head = segregateList(head);
    ListNode* curr = head;
    while(curr != nullptr){
        cout << curr->value << " ";
        curr = curr->next;

    }
    cout << endl;
    head->next = reverse(head->next);
    curr = head;
    while(curr != nullptr){
        cout << curr->value << " ";
        curr = curr->next;

    }
    cout << endl;
}
