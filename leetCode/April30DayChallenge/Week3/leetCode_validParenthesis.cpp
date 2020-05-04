#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> s1, s2;
        for (int i = 0; i < s.length(); i++)
        {
            //--------))))))))))))---------------------
            if (s[i] == ')')    // if right bracket
            {
                if (!s1.empty())
                    s1.pop();   // check for ( bracket  in s1 if found remove top
                else if (!s2.empty())
                    s2.pop();   // if ) not then use *
                else
                    return false;    // if both s1 and s2 empty then false
            }
            //--------(((((((((((((((((((--------------
            else if (s[i] == '(')   // if push i to s1 if (
                s1.push(i);
            //--------*********************------------
            else
                s2.push(i);       // push i to s2 if *
        }

        while (!s1.empty() && !s2.empty())  // only if s1 and s2 contains some value
        {
            if (s1.top() > s2.top())   // check ( index with * index        * --- (
                return false;    // * is at not required location
            s1.pop();   // remove one (
            s2.pop();   // remove one *
        }
        return s1.empty();   // ( stack should be empty for valid string
    }
};

int main(){
    Solution s;
    if(s.checkValidString("((*())*)(*") == true) cout << "PASS\n"; else cout << "FAIL\n";
    if(s.checkValidString("()") == true) cout << "PASS\n"; else cout << "FAIL\n";
    if(s.checkValidString("(*)") == true) cout << "PASS\n"; else cout << "FAIL\n";
    if(s.checkValidString("(*))") == true) cout << "PASS\n"; else cout << "FAIL\n";

    return 0;
}