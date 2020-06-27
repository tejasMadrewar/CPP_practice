#include<bits/stdc++.h>

using namespace std;

int main(){
    long int num,t;
    cin >> num >> t;
    while(t > 0){
        if(num%10 == 0){
            num = num/10;
        }else{
            num  = num -1;
        }
        t--;
    }

    cout << num;
    return 0;
}