#include<iostream>
#include <cstring> 
#include<vector>
#include<string>
#include<map>
using namespace std;

enum {ROW = 3, COL = 3};
enum {X = 1, O = 0};

bool hasTripletoccured(int matrix[ROW][COL], int choice, int x, int y){
    return false;
}

void draw(int matrix[ROW][COL]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(matrix[i][j] == X)
                cout << "X" << " ";
            else if(matrix[i][j] == O)
                cout << "O" << " ";
            else
                 cout << "_" << " ";
        }
        cout << endl;
    }
    cout << endl;      
}

bool isOutofMoves(int array[], int n){
    for(int i = 0; i < n; i++){
        if(array[i] == 0)
          return false;
    }
    return true; 
}

void gamePlay(){
    int matrix[ROW][COL];
    for(int i = 0; i <ROW; i++){
        for (int j = 0; j < COL; j++){
                matrix[i][j] = -1;
        }
    }
    int checkedBoxes[ROW * COL] = {0};
    map<int, pair<int, int>> positionMap = {{1,make_pair(0,0)},
                                            {2,make_pair(0,1)},
                                            {3,make_pair(0,2)},
                                            {4,make_pair(1,0)},
                                            {5,make_pair(1,1)},
                                            {6,make_pair(1,2)},
                                            {7,make_pair(2,0)},
                                            {8,make_pair(2,1)},
                                            {9,make_pair(2,2)}};
    int pos;

    /* check after each move if a triplet has been achieved */
    cout << "You are 'X' and computer is 'O'." << endl;;
    draw(matrix);
    while(1){
        cout << "Your Turn.Input your position from 1 to 9" << endl;
        cin >> pos;
        cout << "You have chosen position " << pos << endl;;
        pair<int, int> place = positionMap[pos];
        matrix[place.first][place.second] = X;
        checkedBoxes[pos-1] = 1;
        draw(matrix);
        if(hasTripletoccured(matrix, X, place.first, place.second)){
            cout << "You have own !!" << endl;;
            break;
        }
        if(isOutofMoves(checkedBoxes,ROW * COL)){
            cout << "Match Drawn !!" << endl;
            break;
        }
        for(int i = 0;  i <  ROW * COL; i++){
            if(checkedBoxes[i] == 0)
                pos = i + 1;
        }
        cout << "Computer has chosen position " << pos << endl;
        place = positionMap[pos];
        matrix[place.first][place.second] = O;
        checkedBoxes[pos - 1] = 1;
        draw(matrix);
        if(hasTripletoccured(matrix, O, place.first, place.second)){
            cout << "Computer has own !!" << endl;;
            break;
        }
        if(isOutofMoves(checkedBoxes,ROW * COL)){
            cout << "Match Drawn !!" << endl;
            break;
        }   
    }
    
}

int main(){
    gamePlay();
}