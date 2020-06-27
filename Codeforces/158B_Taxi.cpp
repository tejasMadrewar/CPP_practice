#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t = 0;
    cin >> n;
    vector<int> v(5, 0);

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v[t]++;
    }

    t = v[4] + v[3] + v[2] / 2;

    v[1] -= v[3];

    if (v[2] % 2 == 1)
    {
        t += 1;
        v[1] -= 2;
    }

    if (v[1] > 0)
        t += (v[1] + 3) / 4;

    cout << t;

    return 0;
}