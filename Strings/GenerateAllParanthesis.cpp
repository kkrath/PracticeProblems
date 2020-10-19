#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * Given a set of parantheis  and n generate all possible combinations of 2*n length such that all those are valid
 */


void generateAllParanthesis(int n, string bracketpair);
void generateAllParanthesis(int const n,char const leftbracket, char const rightbracket, int leftCount, int rightCount, vector<char> permutations);

void generateAllParanthesis(int n, string bracketpair){
    char leftbracket = bracketpair[0];
    char rightbracket = bracketpair[1];
    int leftCount, rightCount;
    leftCount = rightCount = n;
    vector<char> permutations;
    generateAllParanthesis(n, leftbracket, rightbracket, leftCount, rightCount, permutations);


}

void generateAllParanthesis(int const n,char const leftbracket, char const rightbracket, int leftCount, int rightCount, vector<char> permutations){
    if(permutations.size() == 2*n){
        for(auto c: permutations)
            cout << c;
        cout << endl;
        return;
    }

    /* we have two choice to make at each step and we can either choose to select and opening bracket or closing bracket but
        only if we met a criteria */
    if(leftCount > 0){
        permutations.push_back(leftbracket);
        generateAllParanthesis(n, leftbracket, rightbracket, leftCount-1, rightCount, permutations);
        permutations.pop_back();
    }

    if(leftCount < rightCount && rightCount > 0){
        permutations.push_back(rightbracket);
        generateAllParanthesis(n, leftbracket, rightbracket, leftCount, rightCount-1, permutations);
        permutations.pop_back();
    }

    return ;
}

int main(){
    generateAllParanthesis(2, "()");
}