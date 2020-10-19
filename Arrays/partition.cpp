#include<iostream>
#include<vector>
using namespace std;

class Partition{
public:
  bool equalsSumParititon(vector<int> nums){
    if(nums.size() == 0)
      return {0};
    int sum = 0;
    for(int num : nums)
      sum += num;
    if(sum % 2 != 0)
      return {0};
    vector<int> subset;
    return helper(nums, sum / 2 , 0);
  }

private:
      bool helper(vector<int> nums, int curr, int sum){
        if(sum == 0)
          return true;
        if(curr >= nums.size() || sum < 0)
          return false;
        bool choose = (nums, curr + 1, sum - nums[curr]);
        bool loose = (nums, curr + 1, sum);
        return choose || loose;
      }
};


int main(){
  vector<int> nums = {1,2,3,5,4};
  Partition pt;
  cout << pt.equalsSumParititon(nums);
}
