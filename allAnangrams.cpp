/* find all anagrams of a pattern in a given  string */

#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		vector<int> findAnagrams(string text, string pattern){
		int pat_len = pattern.size();
		int text_len = text.size();
		/* array is initialized to keep track of char counts */
		int c_arr[256]{0};
		int t_arr[256]{0};
		vector<int> anagrams;
		for(char c : pattern)
			c_arr[c - 'a']++;

		/* now in the serach text we will look at all pat_len letter words starting from 
		   the zeroth index until text_len - pat_len th index to see if we found a match
		   so that number of char counts in the c_arr is same as that of the match string*/
		for(int i = 0; i < text_len - pat_len + 1 ; i ++){
			cout << "now at index :" << i ;
			if( i < 1){
				int j = i;
				while(j < i + pat_len){
					int idx = text[j] - 'a';
					t_arr[idx]++;
					j++;
				}	
			}else{

				int idx = text[i+pat_len-1] - 'a';
				cout << " " << idx << " " << endl;
				t_arr[idx]++;/* only add the next element as other will remain as is */
			}
			int k;
			for(k = 0; k < 256; k++){
				if(c_arr[k] != t_arr[k])
				break;
			}

			t_arr[text[i] - 'a']--; /* remove the current element as we move forward */
			if(k == 256) /* that means both the strings are anagram */
				anagrams.push_back(i);
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