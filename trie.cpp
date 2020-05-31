/* implememt a prefix Tree or Trie */

/* using a vector and class instead of a struct should increase the performances 
   theoritically but that is ye to be ascertained */
#include<iostream>
#include<string>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
	TrieNode* children[ALPHABET_SIZE];
	bool isEndOfString;
};

TrieNode* getNode(){
	TrieNode *newNode = new TrieNode;
	newNode->isEndOfString = false;
	for(int i = 0; i <  ALPHABET_SIZE; i++)
		newNode->children[i] = NULL;
	return newNode;
}
class Trie {
private:
	TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
       root = getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
    	TrieNode * temp = root;
        for(char c:word){
        	int i  = c - 'a';
        	if(temp->children[i] == NULL)
        		temp->children[i] = getNode();
        	temp = temp->children[i];
        }
        /* mark last node as leaf node */
        temp->isEndOfString = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
    	TrieNode* temp = root;
        for(char c:word){
        	int i = c - 'a';
        	if(temp->children[i] == NULL)
        		return false;
        	temp = temp->children[i];
        }
        return (temp != NULL && temp->isEndOfString);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(char c:prefix){
        	int i = c - 'a';
        	if(temp->children[i] == NULL)
        		return false;
        	temp = temp->children[i];
        }
        return true;
    }
};

int main(){
	string word  = "abc";
	Trie* obj = new Trie();
	obj->insert(word);
	obj->insert("abcd");
	obj->insert("some");
	obj->insert("potter");
	obj->insert("pot");
	cout << "Found ? " << (obj->search("pot") ? "true":"false") << endl;
	cout <<  "Is Prefix ? " << (obj->startsWith("pot") ? "true":"false") << endl;;
} 
 
 