#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int l1 = text1.size();
        int l2 = text2.size();

        int LCS[l1 + 1][l2 + 1];

        // make zero
        for (int i = 0; i < l2 + 1; i++)
            LCS[0][i] = 0;

        // make zero
        for (int i = 0; i < l1 + 1; i++)
            LCS[i][0] = 0;

        int i, j;
        // dp
        for (i = 1; i < l1 + 1; i++)
        {
            for (j = 1; j < l2 + 1; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    LCS[i][j] = 1 + LCS[i - 1][j - 1];
                else
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
        return LCS[i - 1][j - 1];
    }
};

int main(){
    Solution s;
    if(s.longestCommonSubsequence("abcde","ace") == 3) cout << "PASS\n"; else cout << "FAIL\n";
    if(s.longestCommonSubsequence("abc","abc") == 3) cout << "PASS\n"; else cout << "FAIL\n";
    if(s.longestCommonSubsequence("abc","def") == 0) cout << "PASS\n"; else cout << "FAIL\n";


    return 0;
}