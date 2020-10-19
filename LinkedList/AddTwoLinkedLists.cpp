#include<iostream>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int value):value(value),next(nullptr){}
};

ListNode* addLists(ListNode* head1, ListNode* head2){
        if(head1 == nullptr)
            return head2;
        if(head2 == nullptr)
            return head1;
        ListNode* probe1 = head1;
        ListNode* probe2 = head2;
        ListNode* result = nullptr;
        while(probe1 != nullptr || probe2 != nullptr){

        }
}