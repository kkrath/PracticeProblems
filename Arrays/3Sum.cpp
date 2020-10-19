/* this program will find three integers from an given array such that their sum is closest to a given target */

#include<iostream>
#include<vector>

using namespace std;
void helper(vector<int>& nums, vector<int>& sums, vector<int>& list, int curr);

int find3Sum(vector<int>& nums, int target){
    if(nums.size() == 0)
      return 0;
    vector<int> sums;
    vector<int> list;
    helper(nums, sums, list, 0);
    for(auto s: sums)
      cout << s << " ";
    return 0;
}

void helper(vector<int>& nums, vector<int>& sums, vector<int>& list, int curr){
  if(list.size() == 3){
    int sum  = 0;
    for(int s : list)
      sum += s;
    sums.push_back(sum);
    return;
  }
  if(curr >= nums.size())
      return;
  vector<int> newList = list;
  newList.push_back(nums[curr]);
  helper(nums, sums, newList, curr+1);
  helper(nums, sums, list, curr+1);

  return;
}

int main(){
  vector<int> nums = {1,2,-1,4};
  find3Sum(nums, 1);

}
