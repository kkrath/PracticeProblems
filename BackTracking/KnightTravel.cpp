#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class KnightTravel{
    private:
        int row = 0;
        int col = 0;
        vector<pair<int,int>> findPossibleMoves(pair<int,int> pos,vector<vector<int>> &board);
        bool isValidPosition(pair<int,int> pos, int row, int col,  vector<vector<int>> &board);
        void moves(vector<vector<int>> &board, pair<int,int> pos, int count);
    public:
        KnightTravel(){}
        void moves(vector<vector<int>> &board){
            row = board.size();
            col = board[0].size();
            pair<int,int> start(0,0);
            board[0][0] = 1;
            return moves(board, start, 1);
        }
              
};

/* 
 * This method will take the curent snapshot of the board and the position and evaluate 
 * all the possible places the knight can move next. It will also filter out position which
 * are already occupied. It will compile all possible moves list and send it back
 */
vector<pair<int,int>> KnightTravel::findPossibleMoves(pair<int,int> pos, vector<vector<int>> &board){
    vector<pair<int,int>> possibleMoves;
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    for (int k = 0; k < 8; k++) {
        int next_x = pos.first + xMove[k];
        int next_y = pos.second + yMove[k];
        pair<int,int> next = make_pair(next_x, next_y);
        if(isValidPosition(next, row, col, board))
            possibleMoves.push_back(next);
    }
    return possibleMoves;
}

 bool KnightTravel::isValidPosition(pair<int,int> pos, int row, int col, vector<vector<int>> &board){
     return pos.first >= 0 && pos.first < row && pos.second >= 0 && pos.second < col && board[pos.first][pos.second] == 0;
 }


 void KnightTravel::moves(vector<vector<int>> &board, pair<int,int> pos, int count){
     cout << "current count is: " << count << endl;
     if(count == row * col){
         /* all places are filled */
         cout << "count is :" << count << endl;
         for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
     }
     /* if we run out of moves return */

    vector<pair<int,int>> possibleMoves = findPossibleMoves(pos, board);
    cout << "all possible moves are: " << possibleMoves.size() << endl;
    if(possibleMoves.size() == 0)
        return;
        
    for(auto move : possibleMoves){ 
            cout << "Now at : (" << move.first  << "," <<  move.second << ")"<< endl;
            board[move.first][move.second] = count;
            moves(board, move, count+1);
            /* backtrack from here */
            board[move.first][move.second] = 0;
    }

    return;
 }

 int main(){
     KnightTravel tv;
     int board_size = 5;
     vector<vector<int>> board(board_size, vector<int> (board_size, 0));
     tv.moves(board);
 }