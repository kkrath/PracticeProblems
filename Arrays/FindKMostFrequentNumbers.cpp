#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
    public:
        vector<int> findKMostFreqNum(vector<int> &nums, int k){
            vector<int> result;
            unordered_map<int,int> umap;
            for(int num:nums){
                if(umap.find(num) != umap.end())
                    umap[num]++;
                else
                    umap[num] = 1;
            }
            for(auto i : umap){
                if(i.second >= k)
                    result.push_back(i.first);
            }
            return result;
    }
};

int main(){
    vector<int> array = {1,2};int k = 2;
    Solution sol;
    vector<int> res  = sol.findKMostFreqNum(array,k);
    for(int a:res)
        cout << a << ",";
    cout << endl;
}