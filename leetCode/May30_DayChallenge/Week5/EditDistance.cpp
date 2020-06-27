#include <bits/stdc++.h>

using namespace std;

#define PRINT         \
    cout << "PASS\n"; \
    else cout << "FAIL\n";

// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
//
// You have the following 3 operations permitted on a word:
//
// Insert a character
// Delete a character
// Replace a character


void printDP(vector<vector<int>>& aaa){
    for(int i = 0; i < aaa.size(); i++){
        for(int j =0 ; j < aaa[i].size(); j++)
            cout << aaa[i][j] << " ";
            cout << "\n";
    }
    cout << "\n";
}

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // if first string is empty
        // add all characters
        for(int i =0; i <= m; i++)
            dp[i][0] = i;

        // if second string is empty
        // remove all characters
        for(int i =0; i <= n; i++)
            dp[0][i] = i;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                // characters are equal
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                // if not eqaul
                else
                    dp[i][j] = 1 + min(
                                       {dp[i - 1][j - 1], // replace
                                        dp[i - 1][j],     // remove
                                        dp[i][j - 1]});   // replace

                //printDP(dp);
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution s;

    if (s.minDistance("horse", "ros") == 3)
        PRINT
    //horse -> rorse (replace 'h' with 'r')
    //rorse -> rose (remove 'r')
    //rose -> ros (remove 'e')

    if (s.minDistance("intention", "execution") == 5)
        PRINT
    // intention -> inention (remove 't')
    // inention -> enention (replace 'i' with 'e')
    // enention -> exention (replace 'n' with 'x')
    // exention -> exection (replace 'n' with 'c')
    // exection -> execution (insert 'u')

    return 0;
}