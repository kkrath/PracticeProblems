/* find the majority element in an araay */

#include<iostream>
#include<vector>
using namespace std;

class Solution{

public:
	/* we will use Moore's Voting Algorithm to find majority element */
	int findMajorityElement(vector<int>& nums){
		int length = nums.size();
		int count = 0;
		int candidate = 0;
		for(int i = 0;i < length; i++){
			if(count == 0){
				candidate = nums[i];
				count = 0;
			}
			if( candidate == nums[i])
				count++;
			else
				count--;
		}

		return candidate;
	}
};
int main(){
	vector<int> nums = {2,1,2,1,2,1,2,2,2,1,1,1};
	Solution sol;
	cout << "Candidate is: "<< sol.findMajorityElement(nums);
}