#include<bits/stdc++.h>

using namespace std;

int main(){
    int n ;
    cin >> n;
    double ans = 0;

    for(int i = 0 ; i < n; i++){
        double temp;
        cin >> temp;
        ans += temp;
    }

    ans = ans / n;

    cout.precision(17);
    cout << fixed << ans;

    return 0;
}