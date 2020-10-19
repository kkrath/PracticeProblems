#include<iostream>
#include<unordered_set>
using namespace std;


class WordBreak{
    private:

    public:
        bool wordbreak(std::string sentence);
        
};


bool WordBreak::wordbreak(std::string sentence){
    if(sentence.size() == 0)
        return false;
    
    for(int i = 0;  i < sentence.size(); i++){
        
    }

}