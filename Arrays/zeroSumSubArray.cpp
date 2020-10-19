/* sliding window technique */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
  int zeroSumSubArray(vector<int>& nums){
    vector<int> cumulativeSum;
    unordered_map<int,int> umap;
    int maxLength = 0;
    cumulativeSum.push_back(0);
    for(int num:nums){
      int sum = cumulativeSum.back() + num;
      cumulativeSum.push_back(sum);
    }
    for(int i = 0; i < cumulativeSum.size();i++){
      int x = cumulativeSum[i];
      if(umap.find(x)!=umap.end()){
        maxLength = max(maxLength,i - umap[x]);
      }else{
        umap[x] = i;
      }
    }
    return maxLength;
  }
};

int main(){
  vector<int> nums{1,2,1,-3,4,5,2,4,-1,-3};
  Solution *sol = new Solution();
  cout << "maximum length subarray with zero sum :" << sol->zeroSumSubArray(nums);
}
