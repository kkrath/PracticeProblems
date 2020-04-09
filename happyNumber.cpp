/* declaations */
#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;


class Solution{
private:
	unordered_set<int> uset;
	unordered_map<int,int> umap;
	int digitSquareSum(int num){
	  int sumNum = 0;
	  while(num > 0){
             int digit = num % 10;
	     sumNum += digit * digit;
	     num = num / 10; /* floor division */
	  }
	  return sumNum;

	}
public:
 /* to store the number that we have seen already and not get into infinte loop */

	bool isHappyNumber(int num){
		if(uset.find(num) != uset.end())
			return false; // if the number is seen we will simply return false, else we will keep calculating
		int sumNum = 0;
		/* we will use memoization to store the computed result to be refered later */
		if(umap.find(num) != umap.end())
			sumNum = umap[num];
		else{
			sumNum  = digitSquareSum(num);
			umap[num] = sumNum;
		}
		if(sumNum == 1)return true;
		else return isHappyNumber(sumNum);
	}
};

int main(){
	Solution sol;
	cout << (sol.isHappyNumber(19) ? "true":"false") << endl;
}