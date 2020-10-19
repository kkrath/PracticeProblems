/* finding ways to climb N steps - given N steps, find how many ways can you
climb those N steps provided you can ony make either 1 or 2 stps at a time */
#include<iostream>
using namespace std;

class Solution{
private:
	 // dp array to store temporary/intermediate results
	int num_ways(int N,int currStep,int *dp){
		/* base cases*/
		if(currStep == N)
			return 1;  // we have reached the Nth Step - means we have completed the task
		if(dp[currStep] != 0)
			return dp[currStep];
		int result = num_ways(N,currStep+1,dp);
		if((N - (currStep+2)) >= 0){
			result += num_ways(N,currStep+2,dp);
		}
		dp[currStep] = result;
		return result;
	}

public:
	int num_ways(int N){
		int dp[N]{0};
		return num_ways(N,0,dp);
	}

};
int main(){
	Solution sol;
	cout << sol.num_ways(5);
}