#include<iostream>
#include<vector>
using namespace std;

void printList(vector<int> array, int curr, vector<int> sub1, vector<int> sub2){
    if(sub1.size() == array.size()/2 && sub2.size() == array.size()/2){
        for(auto c : sub1)
            cout << c << "";
        cout << ",";
        for(auto c: sub2)
            cout << c << "";
        cout << endl;
        return;
    }
    if(curr >= array.size())
        return;
    vector<int> v1 = sub1;
    v1.push_back(array[curr]);
    printList(array,curr+1, v1, sub2);
    vector<int> v2 = sub2;
    v2.push_back(array[curr]);
    printList(array,curr+1, sub1, v2);
    return;
}

int main(){
    vector<int> array = {2,0,2,1,4,1};
    vector<int> subset1;
    vector<int> subset2;
    printList(array, 0, subset1, subset2);
}
