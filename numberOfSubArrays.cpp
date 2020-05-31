/* given an array find the number of subarrays whose sum is equal to k */
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution{
public:
  int subarraySum(vector<int>& nums, int k){
    vector<int> cumulativeSum;
    int zcount = 0;
    cumulativeSum.push_back(0);
    for(int num:nums){
      if(num==k)zcount++;
      cumulativeSum.push_back(cumulativeSum.back()+num);
    }
    unordered_map<int,int> umap;
    for(int i = 0;i <  cumulativeSum.size(); ++i){
      int x  = cumulativeSum[i] - k;
      if(umap.find(x) != umap.end())
        zcount++;
      else
        umap[cumulativeSum[i]] = i;
    }
    return zcount;
  }
};

int main(){
  vector<int> nums{1,2,1,2,1};
  Solution *sol = new Solution();
  cout << sol->subarraySum(nums,3);
}
