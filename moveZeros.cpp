/* trying out kadane's algorithm */

#include<iostream>
#include<vector>

using namespace std;

class Solution{

public:
	void moveZeros(vector<int>& nums){

		int nzptr = 0;
		int ptr = 0;
		int z_count = 0;

		while(ptr < nums.size()){
			if(nums[ptr] != 0)
				nums[nzptr++] = nums[ptr];
			else
				z_count++;
			ptr++;
		}	
		while(z_count > 0){
			nums[nzptr++] = 0;
			z_count--;
		}
	}
};
	

int main(){
	Solution sol;
	vector<int> V{0,2,9,4,5,-8,7,1};
	sol.moveZeros(V);
	for(int v: V)
		cout << v << ",";
	cout << endl;
}	
