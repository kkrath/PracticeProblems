#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct LinkedNode{
    int data;
    LinkedNode* next;
    LinkedNode(int data):data(data),next(nullptr){}
};

class Items{
    LinkedNode* head;
    LinkedNode* last;
    bool sorted;
    int length;
    public:
        Items(){
            head = last = nullptr;
            sorted = false;
            length = 0;
        }
        int findKthItem(int* array, int k, int n){
            if(!sorted){
                populateSortedList(array,n);
            }
            return removeNode(k);
        }
    private:
        void populateSortedList(int* array, int n){
            sort(array, array+n);
            for(int i = 0; i < n; i++){
                cout << array[i] << " ";
                addNode(new LinkedNode(array[i]));
            }
            cout << endl;
            sorted = true;
        }
        int removeNode(int k){
            int i = 1;
            LinkedNode* probe = head;
            while(probe != nullptr & i < k){
                probe = probe->next;
                i++;
            }
            int val = probe->next->data;
            probe->next = probe->next->next;
            length--;
            return val;
        }

        void addNode(LinkedNode* newNode){
            if (head == nullptr){
                head = newNode;
                last = head;
            }else{
                last->next = newNode;
                last = last->next;
            }
            length++;
        }
    
};

int main(){
    int array[] = {12,7,18,87,21,90,28,1,65,43,17,22,89};
    int n = sizeof(array)/sizeof(int);
    Items items;
    cout << items.findKthItem(array,3, n) << endl;
    cout << items.findKthItem(array,5, n) << endl;
}
