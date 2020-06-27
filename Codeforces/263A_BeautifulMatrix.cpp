#include<bits/stdc++.h>

using namespace std;

int main(){
    int r,c;
    int temp;
    for(int i = 0; i < 5; i++){
        for(int j=0; j < 5; j++){
            cin >> temp;
            if(temp == 1){
                r = i+1;
                c = j+1;
            }
        }
    }

    int d = abs(3-r) + abs(3-c);

    cout << d;
}