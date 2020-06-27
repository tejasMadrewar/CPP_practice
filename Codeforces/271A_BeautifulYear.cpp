#include<bits/stdc++.h>

using namespace std;

bool checkDistinct(int n){
    vector<int> v(10,0);
    while(n > 0){
        int t = n % 10;
        if(v[t] == 1)
            return false;
        v[t]++;
        n = n / 10;
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    while(!checkDistinct(++n));

    cout << n;

    return 0;
}