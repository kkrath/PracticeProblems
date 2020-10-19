/**
 * This program reordres a given string to find a pallindrome. If pallindrome 
 * is not possible; it will retun "NO SOLUTION"
 */

#include<iostream>
using namespace std;

#define STD_RES "NO SOLUTION"

bool ispallindromePossible(std::string);

std::string reorder(std::string str){
    if(!ispallindromePossible(str))
        return STD_RES;
    
}