#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

class Solution
{
public:
    int findComplement(int num)
    {
        int mask = 0, tmp = num;
        while (tmp)
        {
            // shift right
            tmp = tmp >> 1;
            // shift left
            mask = mask << 1;
            // set last bit
            mask = mask | 1;
        }
        // complement and with mask
        return ~num & mask;

    }
};

int main(){
    Solution s;

    if(s.findComplement(1) == 0) PRINT
    if(s.findComplement(5) == 2) PRINT
    if(s.findComplement(2345) == 1750) PRINT


    return 0;
}