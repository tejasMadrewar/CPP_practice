#include<iostream>
#include<vector>

using namespace std;

// move zero to end
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[count++] = nums[i];
                cout << "shift :" << nums[i] << "\n";
            }
        }
        // count is set to first zero element
        while(count < nums.size() ){
            nums[count++] = 0;
        }
    }
};

void printVector(vector<int>& nums){
    for(auto&i : nums){ cout << i << " "; }
    cout << "\n";
}

int main(){
    vector<int> v = {1,2,3,0,8,6,0,3,0,5,7,0,5};
    Solution s;

    printVector(v);
    s.moveZeroes(v);
    printVector(v);

    return 0;
}