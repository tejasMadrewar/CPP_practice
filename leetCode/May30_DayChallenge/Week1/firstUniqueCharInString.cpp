#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

class Solution {
public:
    int firstUniqChar(string s)
    {
        int m[26] = {};
        for (int i = 0; i < s.length(); i++)
            m[s[i] - 'a']++;

        for (int i = 0; i < s.length(); i++)
            if (m[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};

int main(){
    Solution s;
    if(s.firstUniqChar("leetcode") == 0) PRINT
    if(s.firstUniqChar("loveleetcode") == 2) PRINT


    return 0;
}