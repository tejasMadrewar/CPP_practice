#include<bits/stdc++.h>

using namespace std;

int main(){
    int n = 0;
    int bill = 0;
    int idx = 0;

    const vector<int> v = {100,20,10,5,1};

    cin >> n;

#if 1
    while(n > 0){
        if(n < v[idx]){
            idx++;
            continue;
        }

//        int t = n / v[idx];
//        bill += t;
//        n -= t * v[idx];
        bill += n / v[idx];
        n = n % v[idx];
    }

#else

    for(int p = 0; p < v.size(); p++){
        bill += n / v[p];
        n %= v[p];
    }

#endif

    cout << bill;
    return 0;
}