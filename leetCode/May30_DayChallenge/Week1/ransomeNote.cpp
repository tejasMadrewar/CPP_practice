#include<bits/stdc++.h>

using namespace std;

#define PRINT   cout << "PASS\n"; else cout << "FAIL\n";

class Solution {
public:
//    bool canConstruct(string ransomNote, string magazine) {
//        unordered_map<char,int> r;
//        for(auto i :ransomNote)
//            r[i]++;
//
//        for(auto i: magazine){
//            if(r[i] > 0)
//                r[i]--;
//        }
//
//        for(auto i : r){
//            if(i.second != 0)
//            return false;
//        }
//
//        return true;
//    }

    // solution was faster than unordered map
    bool canConstruct(string ransomNote, string magazine) {
        int ch[26]={};
        for(char c: magazine)
            ch[c-'a']++;
        for(char c: ransomNote)
            ch[c-'a']--;
        
        for(int i=0;i<26;i++)
            if(ch[i]<0)
                return false;
        
        return true;
    }
};

int main(){
    Solution s;
if(s.canConstruct("a", "b") == false) PRINT
if(s.canConstruct("aa", "ab") == false) PRINT
if(s.canConstruct("aa", "aab") == true) PRINT


    return 0;
}