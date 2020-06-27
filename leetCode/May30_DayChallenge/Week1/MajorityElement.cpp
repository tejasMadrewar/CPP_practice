#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //int n = nums.size();
        //map<int,int> m;

        //for(auto i : nums) m[i]++;

        //for(auto i:m)
        //    if (i.second > (n / 2)) return i.first;
        //return -1;

        int ans = 0, count = 0;
        for (auto &num : nums)
        {
            if (count == 0)
            {
                ans = num;
                count = 1;
            }
            else
                count += (ans == num) ? 1 : -1;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> v = {3,2,3};
    if(s.majorityElement(v) == 3) PRINT

    v = {2,2,1,1,1,2,2};
    if(s.majorityElement(v) == 2) PRINT

    return 0;
}