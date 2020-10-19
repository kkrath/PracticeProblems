/* given an array counted number x such that x+1 is also in the array */

/* we will store all elements in a hashset initially */

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
	public:
		int countingNums(vector<int> nums){
			int zcount = 0;
			unordered_set<int> uset;
			for(int num:nums){
				uset.insert(num);
			}
			for(int num:nums){
				if(uset.find(num+1) != uset.end())
					zcount++;
			}
			return zcount;
		}
};

int main(){
	Solution sol;
	vector<int> v{1,3,5,7,9,11,12};
	cout << sol.countingNums(v);
}