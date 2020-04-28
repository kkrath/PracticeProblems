/* given an array return an output array of same length so that the corresponding element of the output array
returns the product of all the elements of the except the element*/

/*c++ boilerplate code */
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
  /* this does not use any divison and time complexity is O(n) */
  vector<int> productExceptSelf(vector<int>& s){
    const int n = s.size();
    vector<int> ans(n);
    /* compute prefix vector */
    vector<int> prefix(n+1);
    prefix[0] = 1;
    for(int i = 1; i <= n; i++){
      int xx = prefix[i-1] * s[i-1];
      prefix[i] = xx;
      cout << xx << "," << endl;
    }
    cout << endl;

    vector<int> suffix(n+1);
    suffix[n] = 1;
    for(int i = n-1;i >= 0;i--){
      suffix[i] = suffix[i+1] * s[i];
    }

    for(int i = 0; i < n; i ++){
      cout << prefix[i] << "::" << suffix[i+1] << endl;
      ans[i] = prefix[i] * suffix[i+1];
    }

    return ans;

  }

  vector<int> productExceptSelfFast(vector<int>& nums){
    const int n = nums.size();
    vector<int> output = nums;

    /* Let's calculate the prefix of the array */
    for(int i = 1;i < n; i++){
      output[i] = output[i-1] * nums[i];
    }
    int suffix = 1;
    for(int i = n-1;i > 0;i--){
      output[i] = output[i-1] * suffix;
      suffix *= nums[i];
    }
    output[0] = suffix;
    return output;
  }
};
int main(){
  vector<int> v{1,2,3,4};
  Solution *sol = new Solution();
  vector<int> ans = sol->productExceptSelfFast(v);
  for(auto a:ans)
    cout<<a<<",";
  cout<<endl;
}
