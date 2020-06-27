#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2, s3;
    vector<int> v(26, 0);
    cin >> s1;
    cin >> s2;
    cin >> s3;

    for (auto &i : s3)
        v[i - 'A']++;

    for (auto &i : s1)
        v[i - 'A']--;

    for (auto &i : s2)
        v[i - 'A']--;

    for (auto &i : v)
    {
        if (i != 0)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}