#include <bits/stdc++.h>

using namespace std;

#define PRINT         \
    cout << "PASS\n"; \
    else cout << "FAIL\n";

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        // this solution  is using dp of size numberofRow*numberOfColumn
        int m, n;
        int count = 0;
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // first row and first col
                if (i == 0 || j == 0)
                {
                    dp[i][j] = matrix[i][j];
                    // else where in square
                }
                else if (matrix[i][j] == 1)
                {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                }
                count = count + dp[i][j];
            }
        }

        return count;
    }

    int countSquares1(vector<vector<int>> &matrix)
    {
        // this solution  is using dp of size 2*numberOfColumn
        if (matrix.empty())
            return 0;

        const size_t rowCount = matrix.size();
        const size_t colCount = matrix[0].size();

        int count = 0;
        // prev row
        vector<size_t> prevRow(colCount, 0);
        // copy first row and count 1
        for (size_t c = 0; c < colCount; ++c)
        {
            if (matrix[0][c] == 0)
                continue;
            prevRow[c] = 1;
            ++count;
        }

        // current row
        vector<size_t> curRow(colCount);

        // start from second row
        for (size_t r = 1; r < rowCount; ++r)
        {

            // get current row first column value
            curRow[0] = matrix[r][0] == 1;
            // add to count
            count += curRow[0];

            // start from second column
            for (size_t c = 1; c < colCount; ++c)
            {
                // if 0
                if (matrix[r][c] == 0)
                {
                    curRow[c] = 0;
                }
                // if non zero value
                else
                {
                    // get min neighbour cells and current one value
                    // * *
                    // * x
                    curRow[c] = 1 + std::min(curRow[c - 1], std::min(prevRow[c - 1], prevRow[c]));
                }

                // add to count
                count += curRow[c];
            }

            // swap current with previous
            prevRow.swap(curRow);
        }

        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v;
    v =
        {
            {0, 1, 1, 1},
            {1, 1, 1, 1},
            {0, 1, 1, 1}};
    if (s.countSquares(v) == 15)
        PRINT
    v =
        {
            {1, 0, 1},
            {1, 1, 0},
            {1, 1, 0}};

    if (s.countSquares(v) == 7)
        PRINT

    return 0;
}