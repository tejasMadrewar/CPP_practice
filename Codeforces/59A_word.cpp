#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l = 0, u = 0, n;
    string s;
    cin >> s;
    n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            l++;
        if (s[i] >= 'A' && s[i] <= 'Z')
            u++;
    }

    if (u > l)
    {
        for (auto &a : s) a = toupper(a);
    }
    else
    {
        for (auto &a : s) a = tolower(a);
    }

    cout << s;
    return 0;
}