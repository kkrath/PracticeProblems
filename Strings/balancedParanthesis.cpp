#include<iostream>
#include<stack>

using namespace std;

class Solution{
public:
    bool isBalanced(string seq){
      int balanced  = 0;
      int n  = seq.size();
      for(int i = 0; i < n; i++){
        if(seq[i] == '(' || seq[i] == '*')
          balanced++;
        else if(--balanced == -1)
          return false;
      }

      balanced = 0;
      for(int i = n-1; i >= 0; i--){
        if(seq[i] == ')' || seq[i] == '*')
          balanced--;
        else if(--balanced == -1)
          return false;
      }
      return true;
    }
};

int main(){
  string seq = "((**(*))))";
  Solution *sol = new Solution();
  cout<< "is it balanced ? "<< (sol->isBalanced(seq) ? "true":"false") <<endl;
}
