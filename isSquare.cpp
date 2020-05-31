#include<iostream>
using namespace std;

class Solution{
	public:
		bool isPerfectSquare(int num){
			if( num < 0 )
				return false;
			if(  num == 0 ||  num == 1)
				return true;
			int low = 1;
			int high = 100000;
			while(low <=  high){
				int mid = low + ( high - low ) / 2;
				/* check if mid ** 2 is equal to num */
				int sqr = mid * mid;
				if( sqr == num )
					return true;
				else if( sqr < num )
					low = mid + 1;
				else
					high = mid - 1;
			}
			return false;
		}
};

int main(){
	Solution *sol = new Solution();
	cout << "is perfectsquare ?" << sol->isPerfectSquare(25)<<endl;
}
