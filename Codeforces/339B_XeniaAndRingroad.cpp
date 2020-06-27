#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    long long t = 0;
    long curr = 0, last = 1;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> curr;
        t += curr - last;
        if (curr < last)
            t += n;
        last = curr;
    }

    cout << t;

    return 0;
}