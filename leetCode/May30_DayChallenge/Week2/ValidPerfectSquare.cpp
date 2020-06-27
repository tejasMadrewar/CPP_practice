#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

class Solution {
public:
    bool isPerfectSquare(int num)
    {
        int l = 1, r = num;
        int long long mid,s;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            s = mid*mid;

            if(s == num)
                return true;
            if(s < num)
                l = mid + 1;
            if(s > num)
                r = mid - 1;
        }
        return false;
    }
};

int main(){
    Solution s;
    if(s.isPerfectSquare(16) == true) PRINT
    if(s.isPerfectSquare(14) == false) PRINT

    return 0;
}