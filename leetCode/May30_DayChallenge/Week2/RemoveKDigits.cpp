#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

//Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//Note:
//The length of num is less than 10002 and will be ≥ k.
//The given num does not contain any leading zero.

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        // iterate through all chars of string
        for (auto i : num)
        {
            // if current char is less than ans back
            while (ans.length() && ans.back() > i && k)
            {
                // remove back characters from answer
                ans.pop_back();
                // decrement number of letters to remove
                --k;
            }

            // append current char to ans
            if (ans.length() || i != '0')
                ans += i;
        }

        while (k-- && ans.length())
            ans.pop_back();

        return ans.length() ? ans : "0";
    }
};

int main()
{
    Solution s;
    if(s.removeKdigits("87654321",3) == "54321") PRINT
    if(s.removeKdigits("1234678",3) == "1234") PRINT
    if(s.removeKdigits("1432219",3) == "1219") PRINT
    if(s.removeKdigits("10200",1) == "200") PRINT
    if(s.removeKdigits("10",2) == "0") PRINT

    return 0;
}