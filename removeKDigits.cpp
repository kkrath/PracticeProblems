/* remove k digits from a num represented as string to find if the rest of the string is the smallest number possible */

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution{
	public:
		string removeKdigits(string num, int k){

			int n = num.size();
			stack<char> st;
			/* char stack to push elements from original string */
		
			for(char c:num){
				while(!st.empty() && c < st.top() && k > 0){
					st.pop();
					k--;
				}
				if(!st.empty() || c != '0')
					st.push(c);
			}
			while(!st.empty()  && k > 0){
				st.pop();
				k--;
			}
			if(st.empty())
				return "0";
			while(!st.empty()){
				num[n-1] = st.top();
				st.pop();
				n--;	
			}
			return num.substr(n);
		}
};

int main(){
	string num = "9";
	Solution sol;
	cout << sol.removeKdigits(num,1);
}