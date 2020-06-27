#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else "FAIL\n";

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        if (m > n)
            return false;
        vector<int> count(26, 0);

        // make count of difference
        for (int i = 0; i < m; i++)
        {

            cout << "s1[" << i << "]:" << s1[i] << " "
                 << "s2[" << i << "]:" << s2[i] << "\n";
            // increment char s1[i]
            count[s1[i] - 'a']++;
            // decrement char s2[i]
            count[s2[i] - 'a']--;
        }

        // if difference is zero then found
        if (allZero(count))
            return true;

        // sliding window
        for (int i = m; i < n; i++)
        {
            cout << "s2[" << i << "]:" << s2[i] << " "
                 << "s2[" << (i - m) << "]:" << s2[i - m] << "\n";
            // decrement char [i]
            count[s2[i] - 'a']--;
            // remove count of last char of s2 in frequency map
            count[s2[i - m] - 'a']++;
            // if difference is zero then found
            if (allZero(count))
                return true;
        }
        return false;
    }
    bool allZero(const vector<int> &count)
    {
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    if(s.checkInclusion("ab","eidbaooo") == true) PRINT
    if(s.checkInclusion("ab","eidboaoo") == false) PRINT

    return 0;
}