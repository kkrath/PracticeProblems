#include<iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int data):data(data),next(nullptr){}
};

ListNode*  removeDuplicates(ListNode* head){
    ListNode* curr = head;
    while(curr->next !=nullptr){

        if(curr->data == curr->next->data){
            curr->next = curr->next->next;
        }else
            curr = curr->next;       
    }

    return head;

}

bool isCyclic(ListNode* head){
    ListNode* fast =  head;
    ListNode* slow = head;

    while(fast != nullptr || fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
            return true;
    }
    return false;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head = removeDuplicates(head);
    ListNode* p = head;
    while(p != nullptr){
        cout << p->data;
        p = p->next;
    }
}