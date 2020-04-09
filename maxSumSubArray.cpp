/* finding the maximum sum of contiguous sub array */
#include<iostream>
#include<vector>
using namespace std;

class Solution{

private:
	int partialSum(vector<int> &nums,int i,int j){
	  int sum = 0;
	  for(int p = i;p <= j;p++)	
	    sum += nums[p];
	  return sum;
	 }
public:
	int maxSubarray(vector<int> & nums){
		int maxSum      = INT_MIN;
		int startWindow = 0;
		int endWindow   = 0;
		
		while(startWindow <= endWindow and endWindow < nums.size()){
			int localSum = partialSum(nums,startWindow,endWindow);
			cout << startWindow << "::" <<endWindow << ":" << localSum <<endl;
			if(localSum > maxSum){
				maxSum = localSum;
				endWindow++;
			}else{
				startWindow++;
			}
        }
        return maxSum;
	}
};


int main(){
	Solution sol;
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
	cout << "MaxSum:" << sol.maxSubarray(nums) <<endl;
}