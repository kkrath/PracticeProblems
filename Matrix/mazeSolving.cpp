#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int x, int y, int M, int N){
    return x >= 0 && x < M && y >=0 && y < N;
}
void helper(vector<vector<int>> const maze, int x, int y, vector<vector<int>> solution){
    if(x == (maze.size() - 1) && y == (maze[0].size() - 1)){
        /* we have reached the end of the maze */
        for(int i  = 0; i <  solution.size(); i++){
            for(int j = 0;  j < solution[i].size(); j++){
                if(solution[i][j] == 1)
                    cout << "(" << i << "," <<  j << ")" << "->";
            }
        }
        cout << endl;
        return ;
    }

    /* recursive case */
    if(maze[x + 1][y] == 1 && isSafe(x+1, y, maze.size(), maze[0].size())){
        /* make the selection */
            solution[x + 1][y] = 1;
            helper(maze,x+1, y, solution);
            solution[x + 1][y] = 0;

    }
     if(maze[x][y + 1] == 1 && isSafe(x, y+1, maze.size(), maze[0].size())){
        /* make the selection */
            solution[x][y+1] = 1;
            helper(maze,x, y+1, solution);
            solution[x][y+1] = 0;

    }
    
}

void solveMaze(vector<vector<int>> maze){
    vector<vector<int>> solution = {{0}};
    helper(maze, 0, 0, solution);

}

int main(){
    vector<vector<int>> maze = {{1,0,0,1},
                                {1,1,0,0},
                                {0,1,1,1}};
    solveMaze(maze);
}