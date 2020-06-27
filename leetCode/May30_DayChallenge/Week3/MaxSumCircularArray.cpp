#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int sum = 0;
        int curMaxPrefix = 0, maxSum = INT_MIN;
        int curMinPrefix = 0, minSum = INT_MAX;
        for (auto &num : A)
        {
            // max subarray
            curMaxPrefix = max(curMaxPrefix + num, num);
            maxSum = max(maxSum, curMaxPrefix);

            // min subarray
            curMinPrefix = min(curMinPrefix + num, num);
            minSum = min(minSum, curMinPrefix);

            // sum of array
            sum += num;
        }
        // max can be ( maxSum ) or ( sum -minSum )

        // return non empty subarray sum
        // if(maxSum > 0)
        //        return max(maxSum,sum-minSum);
        //  else
        //        return maxSum;
        return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
    }

};

int main()
{
    Solution s;
    vector<int> v;

    v = {1,-2,3,-2};
    if(s.maxSubarraySumCircular(v) == 3) PRINT

    v = {5,-3,5};
    if(s.maxSubarraySumCircular(v) == 10) PRINT

    v = {3,-1,2,-1};
    if(s.maxSubarraySumCircular(v) == 4) PRINT

    v = {3,-2,2,-3};
    if(s.maxSubarraySumCircular(v) == 3) PRINT

    v = {-2,-3,-1};
    if(s.maxSubarraySumCircular(v) == -1) PRINT

    return 0;
}