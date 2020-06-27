#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, l, m, n, d, count = 0;
    cin >> k >> l >> m >> n >> d;

    for (int i = 0; i < d; i++)
    {
        if ((i + 1) % k == 0 or (i + 1) % l == 0 or (i + 1) % m == 0 or (i + 1) % n == 0)
            count++;
    }

    cout << count;

    return 0;
}