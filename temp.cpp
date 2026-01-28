#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    vector<Node*> child;
    bool end;

    Node(){
        child.resize(26, nullptr);
        end = false;
    }
};


class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node;        
    }

    bool _search_node(Node* nd, string word){
        int l = word.length();
        if(l==0) return nd->end;
        char c_2_match = word.back();
        word.pop_back();
        if(c_2_match=='.'){        
            for(int i=0; i<26; i++){
                if(nd->child[i]){
                    bool res = _search_node(nd->child[i], word);
                    if(res) return true;                    
                }
            }
            return false;
        }
        if(nd->child[c_2_match]) return _search_node(nd->child[c_2_match], word);
        else return false;
    }
    
    void addWord(string word) {
        Node* head =this->root;
        cout << word << endl;
        for(char c: word){
            if(!head->child[c-'a']){
                head->child[c-'a'] = new Node;                
            }
            head = head->child[c-'a'];
        }
        head->end = true;
    }
    
    bool search(string word) {
        return _search_node(this->root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */