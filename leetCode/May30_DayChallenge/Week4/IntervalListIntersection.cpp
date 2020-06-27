#include <bits/stdc++.h>

using namespace std;

#define PRINT         \
    cout << "PASS\n"; \
    else cout << "FAIL\n";

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> intersection;
        int m = A.size();
        int n = B.size();

        int i = 0, j = 0;
        while (i < m && j < n)
        {
            // find start and end of intersection
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);

            // check for valid intersection
            if (start <= end)
                intersection.push_back({start, end});

            // increment the i or j based on upper limit of both A[i] and B[j]
            (A[i][1] < B[j][1]) ? i++ : j++;
        }

        return intersection;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a, b, ans;
    a = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    b = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    ans = {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}};

    if (s.intervalIntersection(a, b) == ans)
        PRINT

    return 0;
}