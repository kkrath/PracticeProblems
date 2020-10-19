/* This program will segregate 0s and 1s from n array */

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int>& nums, int i, int j){
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

void arrange(vector<int>& nums){
  int length =  nums.size();
  if(length == 0)
    return;
  int p1  = 0;
  for(int i = 0; i < length; i++){
    if(nums[i] == 0){
      swap(nums, i, p1);
      p1++;
    }
  }
}

main(){
  vector<int> nums = {1,1,1,0,0,0,0,1,0,1,1,0,0,1,1};
  arrange(nums);
  for(auto i : nums)
    cout << i << " ";
}
