#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> m;
    string s;

    while(n--){
        cin >> s;


        if(m.find(s) == m.end()){
            cout << "OK";
            m[s]++;

        }else{
            cout << s;
            cout << m[s]++;
        }

        cout << "\n";


    }



}