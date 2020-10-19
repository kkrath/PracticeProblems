#include<iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int data):data(data),next(nullptr){}
};
ListNode* reverse(ListNode* head);

bool isPallindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* first = head;
    int count = 0;
    /* find the middle of the list */
    while(fast != nullptr){
        fast = fast->next;
        count++;
        if(count % 2 == 0)
            slow = slow->next;
    }
    cout << slow->data;
    slow->next = reverse(slow->next);
    while(first != nullptr)
    {   
        cout << first->data;first = first->next;
    }
    return true;
}
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

int main(){
    ListNode* head = new ListNode(1);
    head->next =  new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    isPallindrome(head);
}