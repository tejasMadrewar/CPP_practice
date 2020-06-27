#include <bits/stdc++.h>

using namespace std;

#define PRINT         \
    cout << "PASS\n"; \
    else cout << "FAIL\n";


//Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int len = 0;
        int prefixSum = 0;
        unordered_map<int, int> m;
        m[0] = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += ((nums[i] == 1) ? 1 : -1);

            if (m.find(prefixSum) == m.end())
                m[prefixSum] = i;
            else
                len = max(len, i - m[prefixSum]);
        }
        return len;
    }
};

class Solution1{
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        int sum_left[n];
        int min_val, max_val, max_len = 0;

        if(nums[0]==0)
            sum_left[0]=-1;
        else
            sum_left[0]=1;

        // to store min and max prefix sum
        min_val = sum_left[0];
        max_val = sum_left[0];

        // make prefix sum array
        for(int i=1;i<n;i++){
            sum_left[i] = sum_left[i-1] + ((nums[i]==0)? -1 : 1);
            min_val = min(min_val,sum_left[i]);
            max_val = max(max_val,sum_left[i]);
        }

        // make hash map
        int hash[max_val - min_val + 1];
        // init hash map
        memset(hash, -1, sizeof(hash));

        for(int i=0;i<n;i++){

            if(sum_left[i]==0){
                max_len = i+1;
            }

            if (hash[sum_left[i] - min_val] == -1)
                hash[sum_left[i] - min_val] = i;
            else
                max_len = max(max_len, i - hash[sum_left[i] - min_val]);
        }

        return max_len;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v = { 0,1 };
    if(s.findMaxLength(v) == 2) PRINT

    v = { 0,1,0 };
    if(s.findMaxLength(v) == 2) PRINT

    return 0;
}