/* find a subset/subsequence of an array that adds upto K */

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	void findSubSet(vector<int> &nums,vector<int> subset, int curr,int target){
		if(target == 0){
			for(int i:subset)
				cout << i << ",";
			cout << endl;
		}else if(target < 0)
			return;
		else if(curr < 0)
			return;
		else if(target < nums[curr])
			findSubSet(nums, subset, curr - 1, target);
		else{
			findSubSet(nums, subset, curr - 1, target);
			subset.push_back(nums[curr]);
			findSubSet(nums, subset, curr - 1, target - nums[curr]);
		}
		return;
	}
};
int main(){
vector<int> nums{4,5,6,10};
vector<int> subset;
int target = 15;
Solution* sol;
sol->findSubSet(nums, subset, nums.size() - 1, target);
}
