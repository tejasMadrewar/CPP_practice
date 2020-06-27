#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int l =0;

    cin >> s;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z' || i == 0)
            l++;
    }

    if(l == n){
        for(int i=0;i<n;i++){
            if (islower(s[i]))
                s[i] = toupper(s[i]);
            else
                s[i] = tolower(s[i]);
        }
    }

    cout << s;

    return 0;
}