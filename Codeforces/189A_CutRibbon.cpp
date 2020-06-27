#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> v(n + 1,0);

    if (a <= n)
        v[a] = 1;

    if (b <= n)
        v[b] = 1;

    if (c <= n)
        v[c] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i > a && v[i - a] > 0 && v[i] < v[i - a] + 1)
            v[i] = v[i - a] + 1;
            
        if (i > b && v[i - b] > 0 && v[i] < v[i - b] + 1)
            v[i] = v[i - b] + 1;

        if (i > c && v[i - c] > 0 && v[i] < v[i - c] + 1)
            v[i] = v[i - c] + 1;
    }

    cout << v[n];

    return 0;
}