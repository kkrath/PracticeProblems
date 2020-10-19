/*Leetcode Problem#1 - Given an array where all elemnts appear twice except for one,
find that element in linear time and without using an extra space

Time Complexity: O(n)
Space Complexity: O(1)

*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int findUniqueElement(vector<int>& arr){
	unordered_map<int,int> umap;
	for(int ar:arr){
		umap[ar]++;
	}
	for(int ar:arr){
		if(umap[ar] == 1)
			return ar;
	}
	return -1;
}

int main(){
	vector<int> s{1,2,3,3,2,4,4,1,5};
	cout << "Unique Element: " << findUniqueElement(s);

}