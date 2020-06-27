#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {

        cin >> s;
        int n = s.size();
        if (n <= 10)
        {
            cout << s << "\n";
        }
        else
        {
            cout << s[0] << (s.length() - 2) << s[n - 1] << "\n";
        }
    }
    return 0;
}