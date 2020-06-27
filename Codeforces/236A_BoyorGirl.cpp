#include <bits/stdc++.h>

using namespace std;

// if the number of distinct characters in one's user name is odd, then he is a male, otherwise she is a female.

int main()
{
    int n, count = 0;
    string s;

    cin >> s;

    n = s.length();

    sort(s.begin(), s.end());

    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
            count++;
    }

    if (count % 2 == 0)
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";

    return 0;
}