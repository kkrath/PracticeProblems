/* this program will find the maximum length of sub array with equal number of zeros and ones */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
  int findMaxLength(vector<int> nums){
    int maxlength = 0;
    int n = nums.size();
    unordered_map<int,int> umap;
    umap[0]= -1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += (nums[i] > 0) ? 1: -1;
        if(umap.find(sum) == umap.end())
          umap[sum] = i;
        else
          maxlength = max(maxlength,i - umap[sum]);
    }
    return maxlength;
  }
};

int main(){
  vector<int> v = {0,1};
  Solution *sol = new Solution();
  cout << sol->findMaxLength(v);
}
