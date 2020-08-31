#include <bits/stdc++.h>
using namespace std;


class node {
    public:
        char data;
        unordered_map<char,node*> children;
        bool terminal;

        node(char d) {
            data = d;
            terminal = false;
        }   
};

class Trie {
    node* root;
    int cnt;

    public:

    Trie() {
        root = new node('\0');
        cnt = 0;
    }

    void insert(char *w) {  //This is an array passed.
        
        node* temp = root;

        for(int i=0;w[i]!='\0';i++) {
            char ch = w[i];

            if(temp->children.count(ch)) {
                temp = temp->children[ch];
            }
            else {
                node* n = new node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(char *w) {
        node* temp = root;
        for(int i=0;w[i]!='\0';i++) {
            char ch = w[i];
            if(temp->children.count(ch)==0) {
                return false;
            }
            else {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }
};


int main() {

    Trie t;
    char words[][10] = {"a","no","not","nishant","ronaldo"};

    char w[10];
    cin >> w;

    for(int i=0;i<5;i++) {
        t.insert(words[i]);
    }

    if(t.find(w)) {
        cout << "Word is present";
    } else {
        cout << "Word is not present";
    }
    
    return 0;
}
