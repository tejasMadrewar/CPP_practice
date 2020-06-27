#include<bits/stdc++.h>

using namespace std;

int main(){
    int s,n;
    cin >> s >> n;
    vector<pair<int,int>> v(n);

    for(int i = 0 ; i < n; i++){
        cin >> v[i].first;  // dragon strength
        cin >> v[i].second; // bonus strength
    }

    sort(v.begin(),v.end());

    for(int i = 0 ; i < n; i++){
        if (s <= v[i].first){
            cout << "NO";
            return 0;
        }
        else
            s += v[i].second;
    }

    cout << "YES";

    return 0;
}