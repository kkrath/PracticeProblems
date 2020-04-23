/* heapify - we will construct a max heap from a given array */

#include<iostream>
#include<vector>
using namespace std;

#define getLeftChildIdx(parentidx) ((parentidx * 2) + 1)
#define getRightChildIdx(parentidx) ((parentidx* 2) + 2)

class Heap{
private:
	int getMaxIdx(vector<int>& arr,int leftIdx,int rightIdx){
		if(leftIdx >= arr.size())
				return rightIdx;
		else if(rightIdx >= arr.size())
				return leftIdx;
		else return arr[leftIdx] > arr[rightIdx] ? leftIdx : rightIdx;
	}
	void swap(vector<int>& arr,int i,int j){
		int temp   =  arr[i];
		  arr[i]   =  arr[j];
		  arr[j]   =  temp;
	}
	bool hasChildren(vector<int>& arr,int parentIdx){
		return arr.size() >= (parentIdx*2) + 1;
	}
	void heapifyRecursive(vector<int>& arr,int rootIdx){
		if(hasChildren(arr,rootIdx)){
			int maxIdx = getMaxIdx(arr,getLeftChildIdx(rootIdx),getRightChildIdx(rootIdx));
			if(arr[rootIdx] < arr[maxIdx])
				swap(arr,rootIdx,maxIdx);
			heapifyRecursive(arr,maxIdx);
		}else
			return;
	}

public:
	void heapify(vector<int>& arr){
		int lastNonLeafIdx = (arr.size()/2) - 1;
		/* so we will start from last non leaf node */
		for(int i = lastNonLeafIdx; i >= 0 ; i--)
				heapifyRecursive(arr,i);		
	}
};

int main(){
	vector<int> arr{1, 3, 5, 4, 6, 13, 10, 7};
	Heap *heap = new Heap();
	heap->heapify(arr);
	for(int i:arr)
		cout << i << ",";
	cout << endl;
}