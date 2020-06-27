#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int c = 1;
    int ans = 1;
    cin >> n;
    vector<int> v(n,1);

    for(int i =0 ; i < n; i++){
        cin >> v[i];

        if (i > 0)
            if (v[i] >= v[i - 1])
            {
                c++;
                ans = max(ans, c);
            }
            else
                c = 1;
    }

    cout << ans;

    return 0;
}