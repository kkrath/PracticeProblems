/* given  a string s and a matrix find the resultant string */
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
  void shiftS(string &s,string direction,int amount){
    int n = s.size();
    if(amount > n)
      amount = amount % n;
    if(direction == "left"){
      s = s.substr(amount,n-amount)+s.substr(0,amount);
    }else{
      s = s.substr(n-amount,amount)+s.substr(0,n-amount);
    }
  }

public:
  string stringShift(string s, vector<vector<int>>& shift){
    int operation = 0;
    for(int i = 0; i < shift.size(); i++){
      vector<int> ops = (vector<int>)shift[i];
      operation += ops[0] < 1 ? -ops[1] : ops[1];
    }
    if(operation > 0)
      shiftS(s,"right",operation);
    else
      shiftS(s,"left",0-operation);
    return s;
  }

};

int main(){
  string s = "abc";
  vector<vector<int>> shifts{{0,1},{1,2}};
  Solution sol;
  string res = sol.stringShift(s,shifts);
  cout << res;
}
