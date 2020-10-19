#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution{
    public:
        int findEditDistance(string s1, string s2){
            int m = s1.size();
            int n = s2.size();
            unordered_map<string,int> umap;
            return findEditDistance(s1, s2, m, n, umap);
        }
    private:
        int findEditDistance(string s1, string s2, int i, int j, unordered_map<string, int> umap){
            string key = to_string(i) + "::" + to_string(j);
            if (umap.find(key) != umap.end())
                return umap[key];
            if (i == 0)
                return j;
            if (j == 0)
                return i;
            if(s1[i - 1] == s2[j - 1])
                return findEditDistance(s1, s2, i - 1, j - 1, umap);
            else{
                /* insert operation */
                int ins = findEditDistance(s1, s2, i, j - 1, umap);
                int del = findEditDistance(s1, s2, i - 1, j, umap);
                int rep = findEditDistance(s1, s2, i - 1, j - 1, umap);
                int result =  1 + min({ins, del, rep});
                umap[key] = result;
                return result;
            }
        }
};



int main(){
    string s1 = "smitten";
    string s2 = "kitten";
    Solution sol;
    cout << sol.findEditDistance(s1,s2) <<  endl;
}