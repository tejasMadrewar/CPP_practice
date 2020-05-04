#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSum = -99999999;
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                for(int k = i; k<j ; k++){
                    cout << k << "\n";
                    sum  = sum + nums[k];
                }

                cout << "i:" << i <<" j:" << j << " sum:" << sum << " "<<maxSum << "\n";
                maxSum = max(maxSum, sum);
                sum = 0;
            }
        }

        return maxSum;
    }
};

int main(){
    Solution s;
    //vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v = {-2,1};
    //vector<int> v = {1};

    cout << s.maxSubArray(v);


    return 0;
}