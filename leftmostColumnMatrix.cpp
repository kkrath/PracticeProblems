
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimension = binaryMatrix.dimensions();
        int R = dimension[0]; // rows
        int C = dimension[1]; // columns
        int answer = C;
        for(int row = 0; row < R; row++){
            /* we will do a binary search */
            int low = 0;
            int high = C - 1;
            while(high >= low){
                int mid = (high + low) / 2;
                if(binaryMatrix.get(row,mid) == 1){
                    answer = min(answer,mid);
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }       
            }
        }
        if(answer == C)
            answer = -1;
        return answer;
    }

    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimension = binaryMatrix.dimensions();
        int R =  dimension[0];
        int C = dimension[1];
        int answer = C;
        for(int row = 0; row < R; row++){
            for(int col = 0; col < answer & answer > 0; col++){
                if(binaryMatrix.get(row,col) == 1){
                    answer = col - 1;
                    break;
                }
            }
        }
};