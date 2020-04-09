/* buying and selling of stocks given the prices in an array where ith element represent the stock price on that date */

/* let's say there is only one transaction is allowed that is you can buy only once and sell once */

#include<iostream>
#include<vector>
using namespace std;

class Solution{

public:

	Solution(){
		ios::sync_with_stdio(0);
	}
	int maxProfit(vector<int>& prices){
		int profit  = 0;
		
		for(int i = 0; i < prices.size()-1; i++){
			if(prices[i] < prices[i+1]){//we earn some profit
				profit += prices[i+1] - prices[i];
		}
	}
		return profit;
}
};
	
int main(){
	Solution sol;
	vector<int> prices{7,2,1,6,4,5,2,6,7,1,9};
	cout << sol.maxProfit(prices);
}	

	