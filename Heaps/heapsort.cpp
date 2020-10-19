/* using STL heap in program */

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class HeapSort{
public:
	void sort(vector<int>& arr){
		/* create a heap out of the vector */
		make_heap(arr.begin(),arr.end());
		cout<< "The maximum element in the heap is: " << arr.front() << endl;
		/* remove the last element of the heap */
		pop_heap(arr.begin(),arr.end());
		arr.pop_back();

		cout << "The new maximum element in the heap is: " << arr.front() << endl;
		pop_heap(arr.begin(),arr.end());
		arr.pop_back();

		/* adding a new element is heap */
		arr.push_back(9);
		push_heap(arr.begin(),arr.end());

		cout << arr.front();
	}
};

int main(){
	vector<int> v{2,7,4,1,8,1};
	HeapSort *hs =  new HeapSort();
	hs->sort(v);
}

