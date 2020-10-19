#include<iostream>
#include<vector>
using namespace std;

void helper(vector<int> array, vector<int> subset, int curr){
    if(subset.size() == (array.size() / 2)){
        for(auto i : subset)
            cout << i << ",";
        cout << endl;
        return;
    }
    else if(curr >= array.size())
        return;
    /* choose */
    vector<int> newset = subset;
    newset.push_back(array[curr]);
    helper(array, newset, curr+1);
    /* loose */
  
    helper(array, subset, curr+1);
}


void findSubsetMex(vector<int> array){
    vector<int> subset;
    int curr  = 0;
    if(array.size() %2 == 0)
        helper(array, subset, curr);
    
}


void selection(vector<int> const array, int curr, vector<int> sel, int size){

    if(curr >= size)
        return;

    /* loose */
    selection(array, curr+1, sel, size);

    sel.push_back(array[curr]);
    
    if(sel.size() == size/2){
        for(auto i : sel)
            cout << i << ",";
        cout<<endl;
    }else{/* choose */
        selection(array, curr+1, sel, size);
    }
    /* backtrack and remove the element from the list*/
    sel.pop_back();
}



int main(){
    vector<int> array = {3,2,4,1,0,5};
    vector<int> sel;
    selection(array, 0, sel, array.size());
}