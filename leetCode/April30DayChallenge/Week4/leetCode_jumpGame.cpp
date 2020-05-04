#include<bits/stdc++.h>


// reach at last element
// array of values of max right jump


#define vi vector<int>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
//        // first
//        // from back to front
//        int len = nums.size();
//        //last index
//        int last = len - 1;
//        //loop form last-1 to 0
//        for (int i = len - 2; i >= 0; i--)
//        {
//            //min between index+indexvalue and last
//            if ((nums[i] + i) >= last)
//                last = i;
//        }
//        return last == 0;

        // second
        // from front to back
        int maxjump=0;
        for(int i=0;i<=maxjump;i++){
            // max between current maxjump and max jump from current index
            maxjump=max(maxjump,i+nums[i]);
            // if maxjump is greater than last index
            if(maxjump>=nums.size()-1) return true;
        }
        return false;
    }
};

int main(){
    Solution s;

    vector<int> v = {2,3,1,1,4};
    if(s.canJump(v) == true) cout << "PASS\n"; else cout << "FAIL\n";

    v = { 3,2,1,0,4 };
    if(s.canJump(v) == false) cout << "PASS\n"; else cout << "FAIL\n";
    

    return 0;
}