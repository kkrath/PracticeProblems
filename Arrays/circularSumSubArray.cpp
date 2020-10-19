/* find the maximum sum sof a circular sub array */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int maxSumSubArray(vector<int>& A){
        int length = A.size();
        int maxSoFar = INT_MIN;
        int maxEndHere = 0;
        for(int i = 0; i < length; i++){
            maxEndHere += A[i];
            if(maxEndHere < A[i])
              maxEndHere = A[i];
            if(maxEndHere > maxSoFar)
                maxSoFar = maxEndHere;
        }
        return maxSoFar;
    }

public:
    int maxSubarraySumCircular(vector<int>& A) {
        int kadaneSum = maxSumSubArray(A);
        cout << kadaneSum << endl;
        int length = A.size();
        if(length < 3)
            return kadaneSum;
        int circularlength = length * 2 - 1;
        int maxSoFar = INT_MIN;
        int maxEndHere = 0;
        for(int i = 2; i <= length + 1; i++){
            int currElement = A[ i % length];
            cout << currElement << endl;
            maxEndHere +=  currElement;
            if(maxEndHere < currElement)
                maxEndHere = currElement;
            if(maxSoFar <  maxEndHere)
                maxSoFar = maxEndHere;
        }
        return max(maxSoFar,kadaneSum);
        
    }
};

int main(){
    Solution sol;
    vector<int> v{-3,8,-6,-9,2,4,8,-1};
    cout << sol.maxSubarraySumCircular(v) <<endl;
}