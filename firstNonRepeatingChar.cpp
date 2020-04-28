/* find the first non repeating character */

#include<iostream>
#include<string>
using namespace std;
#define ode(x) ((int)x - 97)

class Solution{
public:
  int findFirstNonRepeatingChar(string str){
    int array[26] = {0};
    for(ch:str){
      int idx = ode(ch);
      if(array[idx] == 1)
    }

  }

}
