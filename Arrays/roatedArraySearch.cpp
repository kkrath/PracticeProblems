/* serch in sorted array which is now roated around an unknown pivot */
#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:
	int findPivot(vector<int> &nums){
		/* first we will find the pivot */
		int n = nums.size();
		int low  = 0;
		int high = n - 1;
		int pivot = -1;
		while(high > low){
			int mid = low + (high - low)/2;
			if(mid == 0 || nums[mid] > nums[mid-1]){
				/* we have found one part of the sorted array and we need to look to right*/
				pivot = nums[mid];
				low = mid + 1;
			}else{
				/* we need to look left  */
				high = mid - 1;
			}
		}
		return pivot;
	}
};
int main(){
	vector<int> v{4,5,6,7,0,1,2};
	Solution *sol;
	cout << sol->findPivot(v);
}