#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int count = 0;
    set<char> se;

    getline(cin,s);

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '{' or s[i] == '}' or s[i] == ',' or s[i] == ' ')
            continue;
        se.insert(s[i]);
    }

    cout << se.size();


    return 0;
}