/* Leetcode Programming challanges 
 * see COPYRIGHT file at the top of the source tree.
 * 
 * This product includes code/programs written by the
 * kkrath towards improving hacking skill(https://www.gitub.com/kkrath)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. 
 *
 *
 * @file findAllSubSet.cpp
 * @brief generate all subsets of a given string/array of characters
 * @authot kkrath*
 * @Contact khitish.rath@outlook.com
 **/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class StringUtil{
	public:
		void findAllSubSets(string source,vector<char> res,int start){
			if(start == source.size()){
				for(char c:res)
					cout<< c;
				cout << endl;
			}else{
				vector<char> take = res;
				take.push_back(source[start]);
				findAllSubSets(source,take,start+1);
				findAllSubSets(source,res,start+1);
			}
			return;
		}
};

int main(){
	StringUtil* st;
	vector<char> res{};
	int start = 0;
	st->findAllSubSets("abc",res,start);
}
