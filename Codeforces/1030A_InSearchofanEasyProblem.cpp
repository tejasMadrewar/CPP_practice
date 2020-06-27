#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,t,r=0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if(t == 1)
            r = 1;
    }

    if(r == 1)
        cout << "HARD";
    else
        cout << "EASY";

    return 0;
}