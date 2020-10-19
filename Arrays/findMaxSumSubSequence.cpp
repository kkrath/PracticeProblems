/* Leetcode programming challanges
 * see COPYRIGHT  file at the top of the source tree
 * 
 * This program/code includes solution written by kkrath
 * towards improving hacking skill
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The time complexity of this program is O(2^N) where N is the number of
 * elements in the array.For an array of N elements there are 2^N subsequence
 * possible including empty set. 
 *
 * @file findMaximumSumSubSequence.cpp
 * @brief this program will compute the maximum sum of a subsequence in an array
 * @author kkrath
 * @Contact khitish.rath@outlook.com
 *
 **/
#include<iostream>
#include<vector>
using namespace std;

class ArrayUtil{
private:
	int findMaxSumSubSeq(vector<int> &nums,int sum,int start){
		if(start == nums.size())
		 	return sum;
		else{
		 	int leftSum = findMaxSumSubSeq(nums, sum+nums[start], start+1);
		 	int rightSum = findMaxSumSubSeq(nums, sum, start+1);
		 	return max(leftSum, rightSum);
		}	
	}
public:
	int maxSumSubSeq(vector<int> &nums){
		return findMaxSumSubSeq(nums,0,0);
	}
};

int main(){
ArrayUtil* au;
vector<int> vec{1,-2,4,-3,5,1,-2,5,-6,-1,7,4,-6,-8,9}; 
cout << "maximum sum: " << au->maxSumSubSeq(vec) << endl;
}
