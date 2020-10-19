#include<iostream>
using namespace std;


std::string substring(std::string &str, int start, int end){
    int length = str.size();
    if(start > end)
        return "";
    else if(start < 0)
        return "";
    else if(end >= length)
        return "";
    else{
        char ret_str[end - start];
        for(int i = start; i < end; i++){
            ret_str[i] = str[i];

        }
        return ret_str;
    }
}

int main(){
    /* Testing substring methof for string */
    /* Test case : 1*/
    std::string str = "Jumping";
    if(substring(str, 0, 7) == "")
            return 1005;
    else 
            return 0;
}