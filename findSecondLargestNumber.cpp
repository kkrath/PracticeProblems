/* find the second largest number of a given array */
#include<iostream>
using namespace std;

class Solution{
public:
	int findSecondLargestNumber(int arr[], int length){
	/* we can find the largest number by comparing each number with a maxima so far */
	int max = INT8_MIN;
	int secondMax = max;
	for(int i = 0; i < length; i++){
		if(arr[i] > max){
			secondMax = max;
			max = arr[i];
		}
	}
	return secondMax;
	}
};

int main(){
/* driver code */
int arr[] = {1,2,5,-3,1,4,7};
Solution* sol;
cout << "Maximum :"  <<sol->findSecondLargestNumber(arr,7) << endl;
}
	


