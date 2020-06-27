#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";


class Solution {
public:
// sliding windows solution
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26, 0), res;
        int posCount = 0;

        for(const auto c: p)
            if(++freq[c-'a'] == 1) ++posCount;
        
        for(int i = 0, j = 0, size = s.size(), len = p.size(); j < size; ++j) {
            --freq[s[j]-'a'];
            if(freq[s[j]-'a'] == 0) --posCount;
            else if(freq[s[j]-'a'] == -1) ++posCount;
            if(j-i+1 > len) {
                ++freq[s[i]-'a'];
                if(freq[s[i]-'a'] == 1) ++posCount;
                else if(freq[s[i]-'a'] == 0) --posCount;
                ++i;
            }
            if(posCount == 0) res.push_back(i);
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {0, 6};
    if (s.findAnagrams("cbaebabacd", "abc") == v)
        PRINT

    v = {0, 1, 2};
    if (s.findAnagrams("abab", "ab") == v)
        PRINT
    return 0;
}