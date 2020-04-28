#include<iostream>
#include<vector>
using namespace std;

class Solution {

private:
    int findSmallestNeighbour(vector<vector<int>>& grid,int row,int col,vector<vector<int>> &sumGrid){
        // handle the base case - matrix out of bounds exception
        if(row == grid.size()-1 && col == grid[0].size()-1)
            /* we have reached the end of the matrix */
            return grid[row][col];
        else if( row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return INT_MAX;
        // that means we have a number
        if(sumGrid[row][col] == -1){
          int x = grid[row][col] + min(findSmallestNeighbour(grid,row+1,col,sumGrid),findSmallestNeighbour(grid,row,col+1,sumGrid));
          sumGrid[row][col] = x;
        }
        return sumGrid[row][col];
  }
public:
    int minPathSum(vector<vector<int>>& grid) {

        if( grid.size() == 0)
          return 0;
        int H = grid.size();
        int W = grid[0].size();
        vector<vector<int>> sumGrid(H,vector<int>(W));
        sumGrid[0][0] = grid[0][0];
        // traverse through the entire grid and choose the minimum between
        // the right of down element
        return findSmallestNeighbour(grid,0,0,sumGrid);
    }

    int minPathSumDP(vector<vector<int>>& grid){
      if( grid.size() == 0)
         return 0;
       int H = grid.size();
       int W = grid[0].size();
       vector<vector<int>> dp(H,vector<int>(W));
       for(int row = 0; row < H; ++row){
           for(int col = 0; col < W; ++col){
               /* handle base case */
               if(row == 0 && col == 0)
                   dp[row][col] = grid[row][col];
               else{
                   dp[row][col] = grid[row][col] + min((row==0?INT_MAX:dp[row-1][col]),(col==0?INT_MAX:dp[row][col-1]));
               }
           }
       }
       return dp[H-1][W-1];
    }
};
int main(){
  vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
  Solution *sol = new Solution();
  cout <<  sol->minPathSumDP(grid);
}
