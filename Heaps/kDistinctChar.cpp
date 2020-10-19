/* program to find a substring of a given string s and integer k such that it contains
 at most k unique/distince characters */


#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
public:
	int findSubString(string s, int k){
		/* boundry conditions */
		int length = s.size();
		if( k > length )
			return 0;
		if( s == "" || k == 0)
			return 0;

		/* we will take a hashset to store distince character */

		unordered_map<char,int> umap;
		int left  = 0;
		int right = 0;
		int maxLength = 0;

		while(right < length){
			/* if its a unique character insert into hash map until k is achieved */
			umap[s[right]]++;
			if(umap.size() <= k){
				/* we have a potential candidate */
				maxLength = max(maxLength,right - left +1);
			}else{/* we will shift left until we have umap size under k */
				while(umap.size() > k){
					char t = s[left];
					if(umap[t] > 1)
						umap[t]--;
					else
						umap.erase(t);
					left++;
				}

			}
			right++;	
	}

	return maxLength;
}

};

int main(){
	Solution sol;
	cout << "max length " << sol.findSubString("abcadcacacaca",3);
}