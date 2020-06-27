#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long count = 1;
    string prev, next;

    cin >> prev;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> next;
        if (prev != next)
            count++;

        prev = next;
    }

    cout << count;

    return 0;
}