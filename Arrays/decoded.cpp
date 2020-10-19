/* write a program to decode a an encoded string 
   a = 1, b = 2 .........z= 26 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
private:
		char array[27];
		void findValue(string prefix,string encoded,int pos){	
		/* base case - if we reach end of string, that is our target string and we will
		   print it and then just return */
		if (encoded.empty())
			return;	
		if (pos > encoded.size())
			return;
		 /* if the prefix is greater than 26, we can not choose that path */
		if (encoded.substr(pos,2) > "26" || encoded.substr(pos,1) < "1")
			return;
		string l_prefix = array[stoi(prefix)] + array[stoi(encoded.substr(pos,1))];
		string r_prefix = array[stoi(prefix)] + array[stoi(encoded.substr(pos+1,2))];
		findValue(l_prefix,encoded,pos+1);
		findValue(r_prefix,encoded,pos+3);
		cout << l_prefix << endl;
		cout << r_prefix << endl;
	}
public:
	void possibleDecodedValues(string encoded){
		/* edge cases - empty string 
		   selected two digit is overflown */
	
		for(int i = 1;i < 27;i++)
			array[i] = (char)(96+ i);
		findValue("",encoded,0);

	}
};

int main(){
	string s = "1234";
	Solution sol;
	sol.possibleDecodedValues(s);
}