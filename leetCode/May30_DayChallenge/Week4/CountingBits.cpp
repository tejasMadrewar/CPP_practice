#include <bits/stdc++.h>

using namespace std;

#define PRINT         \
    cout << "PASS\n"; \
    else cout << "FAIL\n";

class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector<int> v(num+1, 0);


        for(int i=1;i<= num; i++) 
            v[i] = v[i/2] + i%2;
        return v;
    }
};



int main()
{
    Solution s;
    vector<int> v;

    v = {0,1,1};

    if(s.countBits(2) == v) PRINT
    if(s.countBits(5) == v) PRINT


    return 0;
}