/* last stone weight using multiset */
#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution{
public:
	int lastStoneWeight(vector<int>& stones) {
		multiset<int> ms{stones.begin(),stones.end()};
		/* initialize multi set */
		for(auto it:ms)
			cout << it << ",";
		cout << endl;
		auto pop_max = [&](){
			int x = *ms.crbegin();
			ms.erase(prev(ms.crbegin()));
			return x;
		};
		
		while(ms.size() >= 2){
			int x = pop_max();
			int y = pop_max();
			cout << x << "::" << y;
			if (x - y > 0){
				ms.insert(x-y);
			}
		}

		return (ms.empty() ? 0 : *ms.begin());
	}
};

int main(){
	vector<int> v{2,2};
	Solution *sol;
	//cout << "last stone weight: " << 
	sol->lastStoneWeight(v);
}