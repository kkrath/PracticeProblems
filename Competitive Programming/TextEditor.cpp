#include<iostream>
#include<stack>
using namespace std;

#define CURSOR '|'
#define NEWLINE '\'

struct CharNode{
    char nodeval;
    CharNode* prev;
    CharNode* next;
    CharNode(char nodeval):nodeval(nodeval),prev(nullptr),next(nullptr){}
};

struct EditNode{
    CharNode* deletedNode;
};

class TextEditor{
    CharNode* head;
    TextEditor::TextEditor(){
        head = new CharNode(CURSOR);
    }
    /* define APIs for the text editor */
    void TextEditor::insert(char nodeval);
    void TextEditor::backspace();
    void TextEditor::del();
    void TextEditor::undo();

};


void TextEditor::insert(char nodeval){
    
}