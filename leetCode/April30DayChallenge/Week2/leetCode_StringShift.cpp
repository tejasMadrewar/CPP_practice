#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {

        int n = s.length();
        for(auto i:shift){
            int d = i[0];
            int cnt = i[1] %n;
            if(d == 0)
                rotate(s.begin(),s.begin() + cnt ,s.end());
            //if(d == 1)
            else
                rotate(s.begin(), s.begin() + n - cnt, s.end());
        }
        return s;
    }
};

int main(){
    Solution s;
    string st = "abc"; 
    vector<vector<int>> shift = { { 0,1 },{ 1,2 } };
    string output = "cab";

    if (output == s.stringShift(st, shift))
        cout << "PASS\n";
    else
        cout << "FAIL\n";


    string te = "Tejas";

    cout << te << "\n";
    rotate(te.begin(), te.begin() + (1 % te.length()), te.end());
    cout << te << "\n";
    rotate(te.begin(), te.begin() + te.length() - (1 % te.length()), te.end());
    cout << te << "\n";

    return 0;
}
