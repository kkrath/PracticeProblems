/* first bad version */
#include<iostream>
using namespace std;

class Solution {
	private:
		bool isBadVersion(int n){
			if (n >= 1150769282 && n <= 1420736637)
				return true;
			else
				return false;
		}

public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int firstbad = 0;
        while(low < high){
            int mid = low + (high - low)/2;
            if(isBadVersion(mid)){/* we will check in left if we can do better */
                high = mid - 1;
                firstbad = mid;
            }else
                low = mid + 1;   
        }
        if(high == low){
        	if(isBadVersion(low))return low;
        }
    	return firstbad;
    }

};
int main(){
	Solution sol;
	cout << sol.firstBadVersion(1420736637);
}