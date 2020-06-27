#include<bits/stdc++.h>

using namespace std;


int main(){
    string a,b;
    cin >> a;
    cin >> b;

    for(int i =0; i < a.length() && i < b.length(); i++){

        if(toupper(a[i]) < toupper(b[i])){
            cout << "-1";
            return 0;
        }

        if(toupper(a[i]) > toupper(b[i])){
            cout << "1";
            return 0;
        }
    }

    cout << "0";

    return 0;
}