/* subarray sum equal to k*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
	int subArraySumEqK(vector<int>& nums,int k){
		int zcount = 0;
		int prefSum = 0;
		unordered_map<int,int> umap;
		for(int i = 0; i <  nums.size(); i++){
			prefSum += nums[i];
			if(umap.find(prefSum - k) != umap.end())
				zcount += umap[prefSum - k];
			umap[prefSum]++;
		}
		return zcount;
	}
};
int main(){
	vector<int> nums{1,2,3};
		Solution *sol = new Solution();
	cout << sol->subArraySumEqK(nums,3);
}
