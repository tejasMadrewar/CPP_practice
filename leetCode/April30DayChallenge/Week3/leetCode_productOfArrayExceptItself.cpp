#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> v(nums.size(), 1);
        int pre = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            v[i] = pre;
            pre = pre * nums[i];
        }
        int post = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            v[i] = v[i] * post;
            post = post * nums[i];
        }
        return v;
    }
};

int main(){
    Solution s;
    vector<int> in = {1,2,3,4};
    vector<int> out = {24,12,8,6};

    if(s.productExceptSelf(in) == out){
        cout << "PASS\n";
    }
    else{
        cout << "FAIL\n";
    }

    return 0;
}