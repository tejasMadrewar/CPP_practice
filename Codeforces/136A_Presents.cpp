#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    //vector<int> v(n,0);
    //vector<int> p(n,0);

    //for(int i = 0 ; i < n; i++){
    //    cin >> v[i];
    //    p[i] = i;
    //}

    //sort(p.begin(),p.end(),[&](auto& a, auto& b)->bool{return v[a] < v[b];});

    //for(auto& i:p)
    //    cout << (i + 1) << " ";

    vector<int> v(105);
    int t;
    for(int i = 1; i <= n; i++){
        cin >> t;
        v[t] = i;
    }

    for(int i = 1; i <= n; i++){
        cout << v[i]  << " ";
    }

    return 0;
}