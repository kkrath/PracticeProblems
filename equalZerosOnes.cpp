/* this program will calculate the maximum subarray of equal number of zeros and ones in
a given array */

#include<iostream>
#include<unordered_map>
using namespace std;

class BinArray{
    public:
        /* we will calculate the cumulative sum of all elements 
           and store the result in a map where first will be the index
           and second will be the sum so far at the same index*/
        int maxArrWithEqZeorsAndOnes(int arr[],int length){
            int maxLength = 0;
            int sumArr[length];
            sumArr[0] = arr[0];
            unordered_map<int,int> umap;
            /* initialize the map for 0th case */
            umap[0] = 0;
            for(int i = 1; i < length; i++){
                if (arr[i] == 0)
                    sumArr[i] = -1 + sumArr[i-1];
                else
                    sumArr[i] = arr[i] + sumArr[i-1];
            }
            for(int i = 0; i < length; i++){
                int sum = sumArr[i];
                if(umap.find(sum)!=umap.end())
                    maxLength = max(maxLength,i - umap[sum] + 1);
                else
                    umap[sum] = i;
            }
            return maxLength;
        }
};

int main(){
   BinArray* binArr;
   int arr[]{1,0,0,1,0,0,0};
   int length = sizeof(arr)/sizeof(int);
   cout << "maximum subarray with equal zeros and ones: " << binArr->maxArrWithEqZeorsAndOnes(arr,length) << endl;
}

