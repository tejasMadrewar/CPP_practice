#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
// find max sub array which contains the same number of 1 and 0
    int findMaxLength(vector<int> &nums)
    {
        int m = 0;
        int count = 0;
        map<int, int> ma;
        ma[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count--;
            if (nums[i] == 1)
                count++;

            if (ma.find(count) == ma.end())
                ma[count] = i;
            else
                m = max(m, i - ma[count]);
        }

        return m;
    }
};
int main(){

    Solution s;
    vector<int> v = {0,1};

    if (s.findMaxLength(v) == 2)
        cout << "PASS\n";
    else
        cout << "FAIL\n";

    v = {0,1,0};
    if (s.findMaxLength(v) == 2)
        cout << "PASS\n";
    else
        cout << "FAIL\n";
    
    v = {1,1,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1};
    cout << s.findMaxLength(v);



    return 0;
}