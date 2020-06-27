#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,a=0;
    string s;
    cin >> n >> s;

    for(int i =0; i < s.length(); i++){
        if(s[i] == 'A')
            a++;
        if(s[i] == 'D')
            a--;
    }

    if( a > 0){
        cout << "Anton";
    }
    if( a < 0){
        cout << "Danik";
    }
    if(a == 0){
        cout << "Friendship";
    }


    return 0;
}