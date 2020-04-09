/* trying out kadane's algorithm */

#include<iostream>
#include<vector>
using namespace std;

/* trying out kadane's algorithm */

class Solution{

public:
	int maxSumSubArray(vector<int>& nums){
	/** 
	*   for each index we will try to find the maximum sum till now and 
	*   store it inside an array 
        **/

		int global_maxima,local_maxima;

		global_maxima = local_maxima = nums[0];

		for(int i = 1; i < nums.size(); i++){
			local_maxima = max(local_maxima+nums[i],nums[i]);
			if(local_maxima > global_maxima)
				global_maxima = local_maxima;
		}
			
		return global_maxima;
	}
};
		

		
int main(){
	Solution sol;
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
	cout << sol.maxSumSubArray(nums);
}