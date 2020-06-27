#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int minIdx = 0, maxIdx = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
        if (v[i] <= v[minIdx])
            minIdx = i;
        if (v[i] > v[maxIdx])
            maxIdx = i;
    }

    int swap = (maxIdx - 0) + (n - 1 - minIdx);

    if (maxIdx > minIdx)
        swap--;

    cout << swap;

    return 0;
}