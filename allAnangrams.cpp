/* find all anagrams of a pattern in a given  string */

#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		vector<int> findAnagrams(string text, string pattern){
		
		/* return variable will be a vector */
		vector<int> anagrams;
		int window = pattern.size();
		int len = text.size();
		if(len < window)
			return anagrams;
		vector<int> phash(26,0);
		vector<int> thash(26,0);	

		int windowStart = 0;
		int windowEnd = 0;
		/* fill the first wiindow - create a window */

		while( windowEnd < window ){
			phash[pattern[windowEnd] - 'a']++;
			thash[text[windowEnd++] - 'a']++;
		}
		windowEnd--;
		/* now we will slide the window and check for anagrams by comparing the hash values */
		while( windowEnd < len ){
			if( phash == thash )
				anagrams.push_back(windowStart);
			windowEnd += 1;
			if(windowEnd != len)
				thash[text[windowEnd] - 'a']++;
			thash[text[windowStart] - 'a']--;
			windowStart++;
		}
		return anagrams;
}

};

int main(){
	Solution sol;
	vector<int> res =  sol.findAnagrams("abcdbacbacd", "abc");
	for(auto r:res)
		cout << r << " ";
}