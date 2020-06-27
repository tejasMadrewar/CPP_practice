#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, a = 0;
    double d;

    cin >> n >> l;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    a = 2 * max(v[0], l - v.back());

    for (int i = 0; i < n - 1; i++)
        a = max(a, v[i + 1] - v[i]);

    d = a / 2.0;

    cout.precision(12);
    cout << fixed << d;

    return 0;
}