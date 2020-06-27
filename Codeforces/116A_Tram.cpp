#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, cap = 0, peo = 0, a, b;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        peo += (b - a);
        cap = max(peo, cap);
    }

    cout << cap;

    return 0;
}