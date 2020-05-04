#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// buy must be followed by sell

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestWithoutStock = 0;
        int bestWithStock = -1e9+5;
        for (auto x : prices){
            bestWithStock    = max(bestWithStock, bestWithoutStock - x);
            bestWithoutStock = max(bestWithoutStock, bestWithStock + x);
            //cout <<"x:" << x <<  " bestWithStock:" << bestWithStock << " bestWithoutStock:" << bestWithoutStock << "\n";
        }
        return bestWithoutStock;
    }
};

int main(){
    // price of share for each day
    vector<int> v = { 7,1,5,3,6,4 };
    Solution s;

    if(s.maxProfit(v) == 7) cout << "PASS"; else cout << "FAIL";

    return 0;
}