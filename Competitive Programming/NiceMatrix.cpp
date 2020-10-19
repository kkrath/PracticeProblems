#include<iostream>
#include<vector>
using namespace std;

/*
 * This program fibds the minimum number of moves required to convert a given
 * n X m matrix into a Nice matrix, a matrix whole rows and colums are pallindromes,
 */

class MatrixOps{
    public:
        int moves(vector<vector<int>> matrix){

            return 0;
        }

        bool isNiceMatrix(vector<vector<int>> &matrix){
                int rows = matrix.size();
                int cols = matrix[0].size();
                for(int i = 0; i <= rows/2; i++){
                    for(int j = 0; j <= cols/2; j++){
                        if((matrix[i][j] != matrix[i][cols - j - 1]) || (matrix[i][j] != matrix[rows - i - 1][j]))
                            return false;
                    }
                }
                return true;
        }
};

int main(){
    vector<vector<int>> matrix{{2,4,2},{2,4,2}};
    MatrixOps* ops;
    cout << "isMatrixNice: " << ops->isNiceMatrix(matrix);

    return 0;
}
