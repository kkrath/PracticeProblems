#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution{

private:
	string removeBackSpace(string X){
		stack<char> st;
		string s = "";
		for(int i = 0; i < X.size(); i++){
			if(X[i] != '#')
				st.push(X[i]);
			else
				if(!st.empty())st.pop();
		}
		while(!st.empty()){
			s.push_back(st.top());
			st.pop();
		}

		return s;
	}
public:
	bool backSpaceCompare(string S, string T){
		
		return removeBackSpace(S)==removeBackSpace(T);
	}
};

int main(){
	Solution sol;
	cout << sol.backSpaceCompare("a##c","#a#c");
}