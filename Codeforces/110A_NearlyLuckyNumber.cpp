#include<bits/stdc++.h>

using namespace std;

bool checkLucky(long long n){
    long long lucky = 0;
    int a;

    while (0 < n)
    {
        a = n % 10;
        n = n / 10;

        if(a == 7 || a == 4)
            lucky++;

    }

    if (lucky == 4 || lucky == 7)
        return true;
    else
        return false;
}

int main(){
    long long n;

    cin >> n;

    if(checkLucky(n))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}