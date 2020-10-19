#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

struct Pair{
    int first;
    int second;
};
void findNonOverlappingSchedule(vector<Pair> const &v){

    int lastIndex  = 0;
    set<int> out;
    out.insert(0);

    for(int i = 0; i < v.size(); i++){
        if(v[lastIndex].second <= v[i].first){
            out.insert(i);
            lastIndex = i;
        }
    }

    for(int i : out){
        cout << "(" << v[i].first << "," << v[i].second << ")" << endl;
    }

}
int main(){
    vector<Pair> activities = { {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
		{6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14} };

	// Sort the activities according to their finishing time
	sort(activities.begin(), activities.end(),
		[](auto const &lhs, auto const &rhs) {
			return lhs.second < rhs.second;
		});
    findNonOverlappingSchedule(activities);

    return 0;
}