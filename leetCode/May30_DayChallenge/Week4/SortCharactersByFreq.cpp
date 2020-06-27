#include <bits/stdc++.h>

using namespace std;

#define PRINT         \
    cout << "PASS\n"; \
    else cout << "FAIL\n";

class Solution {
public:
    string frequencySort1(string s) {
        // create map
        int count[256] = {0};
        // count freq
        for(char c : s)
            count[c] += 1;
        // vector of (freq, char
        vector<pair<int,char>> arr;
        for(int c = 0; c < 256; ++c)
            if(count[c]) arr.push_back({count[c],c});

        // sort vector
        sort(arr.rbegin(), arr.rend());
        string res;

        // make string
        for(auto p : arr)
            res += string(p.first, p.second);

        return res;
    }

    string frequencySort(string s)
    {
        int cnt[128] = {0}; // char -> counter
        int ixs[128];       // position -> char; prepare for sorting

        // char
        for (int c = 0; c < 128; c++) ixs[c] = c; // initiate: fill with all possible chars

        // freq
        for (char c : s) cnt[c]++;
        
        // sort char array by frequency
        sort(begin(ixs), end(ixs), [&](const int a, const int b) { return cnt[a] > cnt[b]; }); // descending
        string res = "";

        // make string from position to chat
        for (int c : ixs)
            res += string(cnt[c], c); // repeat 'c' severeal times
        return res;
    }
};

int main()
{
    Solution s;

    if(s.frequencySort("tree") == "eert" || s.frequencySort("tree") == "eetr") PRINT
    if(s.frequencySort("cccaaa") == "cccaaa" || s.frequencySort("cccaaa") == "aaaccc") PRINT
    if(s.frequencySort("Aabb") == "bbAa" || s.frequencySort("Aabb") == "bbaA") PRINT

    return 0;
}