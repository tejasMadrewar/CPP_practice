#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, sum = 0, ans = 0, cnt = 0;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());
    sum = sum / 2;

    while (ans <= sum)
    {
        cnt++;
        ans += v[n - cnt];
    }

    cout << cnt;

    return 0;
}