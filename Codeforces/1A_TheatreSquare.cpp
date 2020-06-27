#include<bits/stdc++.h>

using namespace std;


int main(){
    int long long a,b,c,s;
    cin >> a >> b >> c;
    //cout << "a:" << a << " b:" << b << " c:" << c << "\n";
    s = ceil(1.0 * a/c) * ceil(1.0 * b/c);
    //cout << "l :" << l << " h :" << h << "\n";
    cout <<  s;

    return 0;
}