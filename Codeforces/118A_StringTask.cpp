#include <bits/stdc++.h>

using namespace std;

int main()
{
    string in;
    string ans;

    cin >> in;

    for (int i = 0; i < in.length(); i++)
    {
        if (in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u' || in[i] == 'A' || in[i] == 'E' || in[i] == 'I' || in[i] == 'O' || in[i] == 'U' || in[i] == 'y' || in[i] == 'Y')
            continue;

        ans += '.';
        ans += towlower(in[i]);
    }
    cout << ans;
    return 0;
}