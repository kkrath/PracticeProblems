/* given an array find the first missing positive integer */
#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		int findSmallestPositiveNumber(vector<int> nums){
			// time comlplexity O(n) and space complexity (n)
			int size = nums.size();
			bool numarr[size+1]{false};

			for(int i = 0; i < size; i++){
				if(nums[i] > 0 && nums[i] <= size)
					numarr[nums[i]] = true;
			}

			for(int i = 1; i <= size; i++){
				if(!numarr[i])
					return i;
			}

			return size + 1;
		}

};

int main(){
	Solution sol;
	vector<int> nums{1,2,0,-1};
	cout << "Missing positive integer: " << sol.findSmallestPositiveNumber(nums);
}