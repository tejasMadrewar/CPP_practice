#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0];
        for(int i = 1; i < n ; i++){
            temp = temp ^ nums[i];
        }
        return temp;
    }
    int singleNonDuplicate1(vector<int>& nums) {
        int l=0,r,mid;
        r = nums.size()-1;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (mid % 2 == 0)
            {
                // if x appears in left half, then 2k+1 elements
                // if in right half, then 2k elements in left side
                if (nums[mid] == nums[mid + 1])
                    l = mid + 1;
                else
                    r = mid;
            }
            else
            {
                if (nums[mid] == nums[mid + 1])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            return nums[l];
        }
    }
};


int main(){
    Solution s;
    vector<int> v = {1,1,2,3,3,4,4,8,8};
    if(s.singleNonDuplicate(v) == 2) PRINT
    v = {3,3,7,7,10,11,11};
    if(s.singleNonDuplicate1(v) == 10) PRINT

    return 0;
}