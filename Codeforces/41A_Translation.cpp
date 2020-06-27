#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.length();

    if (a.length() != b.length()){
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[n - 1 - i])
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}