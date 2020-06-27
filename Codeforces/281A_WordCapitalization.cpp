#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;
    cin >> s;
    if (s.length() > 0)
        s[0] = towupper(s[0]);
    cout << s;

    return 0;
}