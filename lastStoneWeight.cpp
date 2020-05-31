/* Last Stone Weight */

#include<queue>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    	/* let's first convert the array into a max_heap*/
    	priority_queue<int> pq;
    	/* let's create a priority queue from an array */
    	for(int stone:stones)
    		pq.push(stone);

    	while(pq.size()>1) {

    	int x = pq.top();
    	pq.pop();
    	int y = pq.top();
    	pq.pop();

    	int result = (x == y ? -1 : x - y);
    	if(result > 0){
    		pq.push(result);    
    	}

    	}
    	if (pq.size() > 0)
    		return pq.top();
    	else
    		return 0;
    }
};

int main(){
	vector<int> v{2,2};
	Solution *sol = new Solution();
	cout  << sol->lastStoneWeight(v);
}