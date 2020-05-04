#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {


        while (stones.size() > 1)
        {
            sort(stones.begin(), stones.end());

            if (stones[stones.size() - 1] != stones[stones.size() - 2])
            {
                stones[stones.size() - 2] = stones[stones.size() - 1] - stones[stones.size() - 2];
                stones.pop_back();
            }
            else
            {
                stones.pop_back();
                stones.pop_back();
            }

        }

        if (stones.size() == 0)
            return 0;
        else
            return stones[0];
    }
};

int main(){
    Solution s;
    //vector<int> v = {2,7,4,1,8,1};
    vector<int> v = {2,2};
    if(s.lastStoneWeight(v) == 1) cout << "PASS\n"; else cout <<"FAIL\n";


    return 0;
}