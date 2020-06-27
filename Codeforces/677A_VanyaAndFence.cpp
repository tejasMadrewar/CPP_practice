#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,h,w =0;
    cin >> n >> h;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >>v[i];
        if(v[i] <= h)
            w++;
        else
            w += 2;
    }

    cout << w;

    return 0;
}