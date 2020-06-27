#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
int numJewelsInStones(string J, string S) {
       unordered_map<char,int> m; 
        for(char c : J)         m[c]++;
        for(char c : S)
          if(m.count(c)>0)      m['*']++;
        return m['*'];
    }
   // int numJewelsInStones(string J, string S) {
   //     int start = 0;
   //     int ct = 0;
   //     for(auto i:J){
   //         while((start = S.find(i,start)) != string::npos){
   //             ++ct;
   //             start = start + 1;
   //         }
   //     }

   //     return ct;
   // }
};

int main(){
    Solution s;

    if(s.numJewelsInStones("aA","aAAbbb") == 3) cout << "PASS\n"; else cout << "FAIL\n";
    if(s.numJewelsInStones("z","ZZ") == 0) cout << "PASS\n"; else cout << "FAIL\n";

    return 0;
}