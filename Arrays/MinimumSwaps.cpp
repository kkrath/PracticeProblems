#include<iostream>
using namespace std;
void swap(int* arr, int i, int j);
/* find minimum number of swaps to*/
int minSwaps(int array[], int size){
    for(int i = 0; i < size; i++){
        swap(array, i, i+1);
        if(isSorted(array, size))
            return 1;
    }
    
}
void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool isSorted(int* arr, int size){
    for(int i = 0; i < size - 1; i++){
        if(*arr > *(arr+1))
            return false;
    }
    return true;
}


