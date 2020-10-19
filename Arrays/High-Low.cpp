#include<iostream>
using namespace std;


int partition(int array[], int n){
    int idx = -1;
    int max_array[n] = {0};
    max_array[0] = array[0];
    for(int i = 1;  i < n; i++){
        max_array[i] = max(max_array[i-1], array[i]);
    }
    for(int i = n - 1; i > 0; i--){
        if(max_array[i] > max_array[i-1]){
            idx = i - 1;
        }      
    }

    return idx;
}

int main(){
    int array[] = {5,4,3,2,5,6,5,8,9};
    cout << "partition index is: " << partition(array, 6);
}