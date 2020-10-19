/* town judge */

#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
    	if(trust.empty() && N == 1)
    		return 1;
    	if(trust.empty() && N > 1)
    		return -1;
        int trusted_by[N+1]{0};
        int trustee[N+1]{0};
        int candidate = 0;
        for(auto tr : trust){
        	trusted_by[tr[1]]++;
        	trustee[tr[0]]++;
        	if(trusted_by[tr[1]] == N-1){
        		candidate = tr[1];
        	}
        }
        if(candidate > 0 && trustee[candidate] == 0)
        	return candidate;
        else
        	return -1;

    }
};

int main(){
	Solution sol;
	vector<vector<int>> trust;
	trust.push_back({1,2});
	trust.push_back({2,3});
	//trust.push_back({3,1});
	// trust.push_back({3,4});
	// trust.push_back({2,1});
	cout <<  sol.findJudge(3,trust);
}