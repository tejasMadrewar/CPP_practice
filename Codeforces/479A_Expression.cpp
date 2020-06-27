#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,m=0;

    cin >> a >> b >> c;

    m = a + b + c;
    m = max(m, ((a * b) * c));
    m = max(m, ((a + b) * c));
    m = max(m, (a + (b * c)));
    m = max(m, (a * (b + c)));
    m = max(m, ((a * b) + c));

    cout << m;

    return 0;
}