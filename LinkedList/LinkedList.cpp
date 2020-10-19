
#include<iostream>
using namespace std;
struct LinkedNode{
    int value;
    LinkedNode* next;
    LinkedNode(int value):value(value),next(nullptr){}
};

int findCycle(LinkedNode* head){
    LinkedNode* slow = head;
    LinkedNode* fast = head;
    int count = 0;
    while(fast != nullptr){
        fast = fast->next;
        count++;
        if(count % 2 == 0)
            slow = slow->next;
        if(fast == slow)
            return slow->value;
    }
    return 0;

}
  int main(){
      LinkedNode* head = new LinkedNode(7);
      head->next = new LinkedNode(9);
      head->next->next = new LinkedNode(5);
      head->next->next->next = new LinkedNode(3);
      head->next->next->next->next = head->next->next;
      cout << findCycle(head);
  }