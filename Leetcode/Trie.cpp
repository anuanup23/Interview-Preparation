#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    char data;
    unordered_map<char,Node*> children;
    bool terminal;
    Node(char x){
        data = x;
        terminal = false;
    }
};
class trie{
    public:
    Node * root;
    int cnt;
    trie(){
        root = new Node('\0');
        cnt = 0;
    }
    void insert(string w){
        Node* temp = root;
        for(int i = 0; i < w.size(); ++i){
            if(temp->children.count(w[i])){
                temp = temp->children[w[i]];
            }
            else{
                Node * newNode = new Node(w[i]);
                temp->children[w[i]] = newNode;
                temp = newNode;
            }
        }
        temp->terminal = true;
    }
    bool find(string w){
        Node * temp = root;
        for(int i = 0; i < w.size(); ++i){
            if(temp->children.count(w[i])){
                temp = temp->children[w[i]];
            }
            else{
                return false;
            }
        }
        return temp->terminal;
    }
};
int main(){
    trie T;
    while(true){
        string s; cin >> s;
        T.insert(s);
        cout << "Inserted" << endl;
        string f; cin >> f;
        cout << T.find(f) << endl;
    }
}