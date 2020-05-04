#include<bits/stdc++.h>
using namespace std;

//class Solution {
//public:
//    int rangeBitwiseAnd(int m, int n) {
//        int r = m;
//        for(int i = m+1; i < n+1;i++){
//            r = r & i;
//        }
//        return r;
//    }
//};

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        //int not_common = 0;
        //    cout << "m:" << m << " n:" << n << "\n";
        //while(m != n) {
        //    not_common++;
        //    m >>= 1;
        //    n >>= 1;
        //}
        //return m << not_common;

        cout << m << " " << n <<  "\n";
        while (n > m){
            n = n & n - 1;
            cout << n <<  " ";
        }
        cout << "\n" << (m&n) << "\n";
        return m & n;
    }
};

int main(){
    Solution s;
    if(s.rangeBitwiseAnd(5,7) == 4) cout << "PASS\n"; else cout << "FAIL\n";
    if(s.rangeBitwiseAnd(0,1) == 0) cout << "PASS\n"; else cout << "FAIL\n";
    if(s.rangeBitwiseAnd(256,1234) == 0) cout << "PASS\n"; else cout << "FAIL\n";
    if(s.rangeBitwiseAnd(150,1235) == 0) cout << "PASS\n"; else cout << "FAIL\n";

    return 0;
}