#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, t;
    string s;
    cin >> n >> t >> s;

    for (int j = 0; j < t; j++)
        for (int i = s.length() - 1; i > 0; i--)
        {
            if (s[i] == 'G' && s[i - 1] == 'B'){
                swap(s[i], s[i - 1]);
                i--;
            }
        }

    cout << s;

    return 0;
}