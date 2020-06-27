#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

//Implement a trie with insert, search, and startsWith methods.
class Trie {
  private:
    map<char, Trie*> next = {};
    bool isword = false;
public:
    Trie() {}

    void insert(string word)
    {
        Trie* root = this;
        for (char ch : word) {
            if (!root->next.count(ch)) { root->next[ch] = new Trie(); }
            root = root->next[ch];
        }
        root->isword = true;
    }

    bool search(string word) {
        Trie* root = this;
        for (char ch : word) {
            if (!root->next.count(ch)) { return false; }
            root = root->next[ch];
        }
        return root->isword;
    }
    bool startsWith(string prefix) 
    {
        Trie* root = this;
        for (char ch : prefix) {
            if (!root->next.count(ch)) { return false; }
            root = root->next[ch];
        }
        return true;
    }
};

class Trie1 {
public:
    /** Initialize your data structure here. */
    bool eow;
    Trie1* children[26];
    
    Trie1(): eow(false) {
        ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
        for (int i = 0; i < 26; i++) children[i] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie1* temp = this;
        for (int i = 0; i < word.size(); i++) {
            if (!temp->children[word[i] - 'a']) {
                temp->children[word[i] - 'a'] = new Trie1();
            }
            temp = temp->children[word[i] - 'a'];
        }
        temp->eow = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie1* temp = this;
        for (int i = 0; i < word.size(); i++) {
            if (!temp->children[word[i] - 'a']) return false;
            temp = temp->children[word[i] - 'a'];
        }
        return temp->eow;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie1* temp = this;
        for (int i = 0; i < prefix.size(); i++) {
            if (!temp->children[prefix[i] - 'a']) return false;
            temp = temp->children[prefix[i] - 'a'];
        }
        return true;
    }
};

int main()
{
    Trie t;
t.insert("apple");
if(t.search("apple") == true) PRINT    // returns true
if(t.search("app") == false) PRINT     // returns false
if(t.startsWith("app")  == true) PRINT // returns true
t.insert("app");
if(t.search("app") == true) PRINT     // returns true

    return 0;
}