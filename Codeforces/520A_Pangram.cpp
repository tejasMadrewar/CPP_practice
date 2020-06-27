#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int n;
    cin >> n;
    cin >> s;
    set<char> se;

    for(auto& i:s){
        if(i <= 'Z' and i >= 'A')
            se.insert('a' + i - 'A');
        else
            se.insert(i);
    }

    if(se.size() == 26)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}