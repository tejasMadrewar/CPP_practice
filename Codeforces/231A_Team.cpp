#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    int count = 0;
    int temp;
    int t = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            cin >> temp;
            t = t + temp;
        }
        if (t >= 2)
            ++count;
        t =0;
    }

    cout << count;

    return 0;
}