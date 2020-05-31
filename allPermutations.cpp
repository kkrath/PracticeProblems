/* write a program to find if any permutation of string s1 is present in s2 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
	public:
		bool checkInclusion(string s1, string s2){
			int windowSize = s1.size();
			int len = s2.size();
			if(len < windoSize)
				return false;
			/* two hash for comparing the permutations */
			vector<int> phash(26,0);
			vector<int> thash(26,0);

			int windowStart  = 0;
			int windowEnd = 0;
			while(windowEnd < windowSize){
				phash[s1[windowEnd] - 'a']++;
				thash[s2[windowEnd++] - 'a']++;
			}
			windowEnd--;
			while(windowEnd < len){
				if(phash ==  thash)
					return true;
				/* now shift the window by 1 position */
				windowEnd += 1;
				if(windowEnd != len)
					thash[s2[windowEnd] - 'a']++;
				thash[s2[windowStart++] - 'a']--;
			}

			return false;

		}
};

int main(){
	Solution sol;
	cout << sol.checkInclusion("cde","abdebcdebca") << endl;
}