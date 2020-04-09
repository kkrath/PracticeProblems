#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution{

public:
	vector<vector<string>> groupAnagrams(vector<string>& str){
		unordered_map<string,vector<string>> umap;
		for(string s:str){
			string s2 = s;
			sort(s2.begin(),s2.end());
			umap[s2].push_back(s);
		}
		vector<vector<string>> s;
		for(auto p:umap)
			s.push_back(p.second);
		return s;
}
};

int main(){
	Solution sol;
	vector<string> v{"ate","ant","tea","tan","eat","bat"};
	vector<vector<string>> s = sol.groupAnagrams(v);
	for(auto pp:s){
		for(auto mm:pp){
			cout << mm << ",";
		}
		cout << endl;
	}
}
