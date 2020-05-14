/* given an array find the first missing positive integer */
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
	void swap(int *a, int *b){
			int temp = *b;
			*b = *a;
			*a = temp;
		}
	int shiftAllNonPositiveNumbersLeft(int *arr,int size){
			int j = 0; // j is the pointer to track negetive numbers;
			for(int i = 0;i < size;i++){
				if(arr[i] <= 0){
					swap(&arr[i],&arr[j]);
					j++; // now j will point to new left position
				}
			}

			return j; // return the starting position of all the positive integers
		}
		void shiftAllNonPositiveNumbersRight(int *arr,int size){
			int j = size - 1;
			for(int i = size-1; i >= 0; i--){
				if(arr[i] <= 0){
					swap(&arr[i],&arr[j]);
					j--;
				}
			}
		}

		int findMissingPositiveNumber(int *arr,int size){

			for(int j = 0; j < size; j++){
				int x =abs(arr[j]) - 1;
				if (x <  size && arr[x] > 0){
					arr[x] = -arr[x];
				}
			}

			for(int i = 0; i < size; i++){
				if(arr[i] > 0)
					return i + 1;
			}

			return size + 1;
		}		

	public:
		int findSmallestPositiveNumber(vector<int> nums){
			// time comlplexity O(n) and space complexity (n)
			int size = nums.size();
			bool numarr[size+1]{false};

			for(int i = 0; i < size; i++){
				if(nums[i] > 0 && nums[i] <= size)
					numarr[nums[i]] = true;
			}

			for(int i = 1; i <= size; i++){
				if(!numarr[i])
					return i;
			}

			// if we did not find any number which is positive that means everthing is at its 
			// designated place
			return size + 1;
		}
		int findSmallestPositiveNumber(int *arr,int size){
			/* segregate all non positive numbers to left */
			int shift = shiftAllNonPositiveNumbersLeft(arr,size);

			return findMissingPositiveNumber(arr+shift,size-shift);
		}

		
};

int main(){
	Solution sol;
	vector<int> nums{11,12,13,-1,3};
	int arr[4] = {11,12,10,13};
	cout << "Missing positive integer: " << sol.findSmallestPositiveNumber(arr,4) << endl;
	for(int i = 0; i < 4; i++){
		cout << arr[i] << "," ;
	}
	cout<<endl;
}