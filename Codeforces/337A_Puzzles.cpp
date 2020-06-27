#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;

    cin >> m >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int diff = v[n - 1] - v[0];

    for (int i = 0; i < n - (m - 1); i++)
    {
        int temp = v[i + (m - 1)] - v[i];
        diff = min(diff, temp);
    }

    cout << diff;

    return 0;
}