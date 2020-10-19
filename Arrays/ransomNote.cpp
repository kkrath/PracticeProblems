/* ransom note problem */
#include<iostream>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int c_array[26]{0};
        for(auto ch:magazine){
            c_array[ch - 'a']++;
        }
        for(auto ch:ransomNote){
            if(--c_array[ch - 'a'] <= 0)
                return false;  
    	}
    	return true;
	}

};

int main(){
	Solution sol;
	cout << sol.canConstruct("a", "b");
}