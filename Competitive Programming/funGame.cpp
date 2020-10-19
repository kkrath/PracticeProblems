#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void backtracking(vector<int> original_array, int curr, int total_sum, vector<int> selection, int curr_sum, int minDiff){
/* boundary and exit condition */
if(selection.size() >= original_array.size()/2){
       int firstSum = total_sum - curr_sum;
       minDiff = min(minDiff, abs(firstSum - curr_sum));
       cout << curr_sum << "," <<  total_sum - curr_sum << endl;
       return;
}
if(curr >= original_array.size())
    return;

vector<int> new_selection = selection;
new_selection.push_back(original_array[curr]);
backtracking(original_array, curr+1, total_sum, new_selection, curr_sum+original_array[curr],minDiff);
backtracking(original_array, curr+1, total_sum, selection, curr_sum,minDiff);

}
int main(){
    vector<int> array = {1,2,3,4};
    vector<int> selection;
    backtracking(array, 0, 10, selection, 0, INT_MAX);
}