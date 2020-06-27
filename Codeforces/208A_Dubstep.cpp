#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = 3;

    for (int i = 3; i <= s.length(); i++)
    {
        //if (s[n - 3] == 'W' and s[n - 2] == 'U' and s[n - 1] == 'B')
        if (s.substr(n - 3, 3) == "WUB")
        {
            n -= 3;
            if (n != 0 && s[n - 1] != ' ' && i != s.length())
            {
                s[n++] = ' ';
            }
        }
        s[n] = s[i];
        n++;
    }

    cout << s.substr(0, 0 + n - 1);

    return 0;
}