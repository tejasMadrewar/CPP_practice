#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    string h = "hello";
    int counter = 0;

    int n = s.length();
    int m = h.length();

    for(int i = 0; i< n ; i++){
        if(s[i] == h[counter])
            counter++;
        if(m == counter)
            break;
    }

    if(counter == h.length()){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}