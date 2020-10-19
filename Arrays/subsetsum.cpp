/* This is a Leetcode Challange 
 * See the COPYRIGHT file at the top of the source tree 
 *
 *
 * @file subsetsum.cpp
 * @brief this program finds all the subsets of an array which sums upto a certain target
 * @author kkrath
 * @contacr khitish.rath@outlook.com 
 **/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class ArrayUtils{
private:
	int findSubSetSumRec(vector<int> nums, int curr, int target){
		/* base cases */ 
		//there is only one subset which adds up to 0 and that is empty subset
		if(target == 0)
			return 1;
		//there is no subset which adds up to negetive sum, as all numbers are positives
		else if(target < 0)
			return 0;
		else if(curr < 0)
			return 0;
		/* recursive case */
		else if(target < nums[curr])
			// we can not reach target if we take the curr element into account
			return findSubSetSumRec(nums, curr - 1, target);
		else
		      // everything else
		      return findSubSetSumRec(nums, curr - 1, target - nums[curr]) +
				findSubSetSumRec(nums, curr - 1, target);
	}
	int findSubsetSumDP(vector<int> nums, int curr, int target, unordered_map<string,int> dp){
		string key = to_string(target) + ":" + to_string(curr);
		int to_return  = 0;

		if(dp.find(key) != dp.end())
			return dp[key];
		else if(target == 0)
			return 1;
		else if(target < 0)
			return 0;
		else if(curr < 0)
			return 0;
		else if(target < nums[curr])
			to_return = findSubsetSumDP(nums, curr - 1, target,dp);
		else
			to_return = findSubsetSumDP(nums, curr - 1, target - nums[curr], dp) +
					findSubsetSumDP(nums, curr - 1, target, dp);
		dp[key] = to_return;
		return to_return; 
	}
public:
	int findSubSetSum(vector<int> nums, int target){
		unordered_map<string,int> umap;
		int end = nums.size();
		//return findSubSetSumRec(nums, end - 1,target);
		return findSubsetSumDP(nums, end - 1, target, umap);

	}
};

int main(){
ArrayUtils* au;
vector<int> vec{2,4,6,10};
int target = 16;
cout << "Number of Subsets which add up to "<<target << " : " << au->findSubSetSum(vec,target)<< endl;
}
