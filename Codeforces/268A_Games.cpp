#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<pair<int, int>> v;
    int n;
    int count = 0;
    cin >> n;
    v.resize(n,{-1,-1});

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        cin >> v[i].second;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (v[i].first == v[j].second)
                count++;
        }
    }

    cout << count;

    return 0;
}