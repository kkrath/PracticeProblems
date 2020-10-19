/* This program will partition an array into two equal sum halves */

#include<iostream>
using namespace std;
void printSubset(int array[], int size, int r, int curr, int idx, int subset[]);

bool isPartitionPossible(int array[], int size, int r){
    bool ans = false;
    int sum = 0;
   
    int subset[r];
    printSubset(array, size, r, 0, 0, subset);

    return ans;
}

void printSubset(int array[], int size, int r, int curr, int idx, int subset[]){
    /* base condition */
    if(idx == r){
        for(int j = 0; j < r; j++)
            cout << subset[j] << " ";
        cout <<  endl;
        return;
    }

    if(curr >= size)
        return;

    /* either we select the current element or not */
    subset[idx] = array[curr];
    printSubset(array, size, r, curr+1, idx+1, subset);
    printSubset(array, size, r, curr+1, idx, subset);
     
}
int main(){
    int array[] = {1,2,3,4,5};
    isPartitionPossible(array, 5, 3);
    return 0;
}
