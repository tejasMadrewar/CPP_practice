#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t = i % 2;
        if (i > 0)
            cout << "that ";

        if (t == 0)
            cout << "I hate ";
        if (t == 1)
            cout << "I love ";
    }

    cout << "it";

    return 0;
}