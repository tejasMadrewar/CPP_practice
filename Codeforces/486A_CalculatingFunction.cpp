#include <bits/stdc++.h>

using namespace std;

int main()
{
    int long long n, sum = 0;
    cin >> n;

//    for (int i = 0; i < n; i++)
//    {
//        if (i % 2 == 0)
//            sum -= (i + 1);
//        else
//            sum += (i + 1);
//    }

    if( n % 2 == 0){
        sum = (n+1) /2;
    } else{
        sum = -(n+1) /2;
    }

    cout << sum;

    return 0;
}