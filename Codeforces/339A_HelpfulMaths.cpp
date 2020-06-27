#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    vector<int> v;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            v.push_back(1);
        if (s[i] == '2')
            v.push_back(2);
        if (s[i] == '3')
            v.push_back(3);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
            cout << "+";
    }

    return 0;
}