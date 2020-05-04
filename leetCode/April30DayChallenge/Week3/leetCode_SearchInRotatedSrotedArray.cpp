#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1) return -1;
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }
        
        int lo = 0, hi = nums.size()-1;
        
        while (lo < hi) {
			if (nums[lo] == target) return lo;
            if (nums[hi] == target) return hi;
            int pivot = (lo + hi)/2;
            if (nums[pivot] == target) return pivot;
            
            // left is sorted
            if (nums[lo] < nums[pivot]) {
                // if target is not within the sorted range then it means
                // the target is within the right unsorted half
                if (target > nums[pivot] || target < nums[lo]) {
                    lo = pivot + 1;
                } else {
                    hi = pivot - 1;
                }
            }
            
            // right is sorted
            else  {
                // if target is not within the sorted range then it means
                // the target is within the left unsorted half
                if (target < nums[pivot] || target > nums[hi]) {
                    hi = pivot - 1;
                } else {
                    lo = pivot + 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> v = {1,2,3,4,5,9};
    auto a = find(v.begin(),v.end(),11);

    if(a == v.end()){
        cout << "Not Found\n";
    }else{
        cout << (a - v.begin());
    }

    return 0;
}