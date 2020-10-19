#include<iostream>
using namespace std;

struct LinkedNode{
    int value;
    LinkedNode* next;
    LinkedNode* random;
    LinkedNode(int value):value(value),next(nullptr),random(nullptr){}
};

LinkedNode* cloneList(LinkedNode* head){
    
}