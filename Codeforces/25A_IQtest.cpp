#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    int even = 0, lastodd = 0, lasteven = 0;
    int x;

    for(int i = 1 ; i <=n; i++){
        cin >> x;

        if(x %2 == 0){
            even++;
            lasteven = i;
        }else{
            even--;
            lastodd = i;
        }
    }
    cout << (even > 0 ? lastodd : lasteven);

    return 0;
}