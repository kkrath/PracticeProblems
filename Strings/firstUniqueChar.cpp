/* find the first the non-repeating character in a given string and return its index */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution{
public:
	int firstUniqChar(string s) {
		if(s.empty())
			return -1;
        int length = s.size();
        int array[26] = {0};
        int ans = -1;
        for(char c:s){ 
           array[c - 'a']++;
        }
        for(int i = 0;i < length;i++){
            if(array[s[i] - 'a'] == 1){
            	ans = i;
            	break;
            }
        }
        return ans;
    }
	int firstUniqChar2(string s) {
		
		int length = s.size();
		unordered_map<char,int> umap;
		for(auto c:s){
			umap[c]++;
		}
		for(int i = 0; i < length; i++){
			if(umap[s[i]] == 1) return i;
		}
		return -1;
	}

};
int main(){
	string str = "lonnlovegood";
	Solution sol;
	cout << "FNRC: " << sol.firstUniqChar2(str);

}