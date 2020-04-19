#include<iostream>
using namespace std;

typedef struct Node{
    int value;
    Node* next;
    int minValSoFar;
    Node(int val):value(val),next(NULL){}
} Node;

Node* getNewNode(int val){
    Node* newNode = new Node(val);
    return newNode;
}

class MinStack {
private:
    Node* head;
public:
    /** initialize your data structure here. */
    MinStack() {
        head = NULL;
    }
    
    void push(int x) {
        if(head == NULL){
            head = getNewNode(x);
            head->minValSoFar = x;
        }else{
            Node* temp = getNewNode(x);
            temp->next = head;
            temp->minValSoFar = min(temp->value,head->minValSoFar);
            head = temp;
        }
       
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->value;
        
    }
    
    int getMin() {
        return head->minValSoFar;    
    }
};



int main(){

 MinStack* obj = new MinStack();
 obj->push(2);
 obj->push(4);
 obj->push(-1);
 obj->push(6);
 obj->push(0);
 obj->push(8);
 obj->pop();
 cout << "Top:" << obj->top() << endl;;
 cout << "Min:" << obj->getMin() << endl;
} 

 