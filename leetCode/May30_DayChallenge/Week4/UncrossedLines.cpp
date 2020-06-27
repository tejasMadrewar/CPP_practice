#include <bits/stdc++.h>

using namespace std;

#define PRINT         \
    cout << "PASS\n"; \
    else cout << "FAIL\n";

// We write the integers of A and B (in the order they are given) on two separate horizontal lines.
//
// Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:
//
// A[i] == B[j];
// The line we draw does not intersect any other connecting (non-horizontal) line.
// Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.
//
// Return the maximum number of connecting lines we can draw in this way.


// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j)
            {
                if (A[i] == B[j])
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[M][N];
    }
};

// Time: O(MN)
// Space: O(min(M, N))
class Solution1 {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int M = A.size(), N = B.size();
        if (M < N) swap(M, N), swap(A, B);
        vector<int> dp(N + 1);
        for (int i = 0; i < M; ++i) {
            int prev = 0;
            for (int j = 0; j < N; ++j)
            {
                int cur = dp[j + 1];
                if (A[i] == B[j])
                    dp[j + 1] = 1 + prev;
                else
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                prev = cur;
            }
        }
        return dp[N];
    }
};

int main()
{
    Solution s;
    vector<int> a, b;

    a = {2, 5, 1, 2, 5};
    b = {10, 5, 2, 1, 5, 2};

    if (s.maxUncrossedLines(a, b) == 3) PRINT

    a = {1, 4, 2};
    b = {1, 2, 4};
    if (s.maxUncrossedLines(a, b) == 2) PRINT

    a = {1, 3, 7, 1, 7, 5};
    b = {1, 9, 2, 5, 1};
    if (s.maxUncrossedLines(a, b) == 2) PRINT

    return 0;
}