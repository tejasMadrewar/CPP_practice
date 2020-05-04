#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    map<int,int> temp;
    int singleNumber(vector<int>& nums) {
    //    // generate map
    //    for(int i = 0; i< nums.size(); i++){
    //        
    //        if(temp.find(nums[i]) == temp.end()){
    //               temp.insert({nums[i] ,1});
    //            
    //        }
    //        else{
    //            auto el = temp.find(nums[i]);
    //            if(el != temp.end()) el->second = el->second + 1;
    //         
    //        }
    //    }

    //    // find value with 1
    //    for(auto& i:temp){
    //        if(i.second == 1)
    //        return i.first;
    //    }
    //    
    //    return -1;
    int a = 0;
    for(auto x:nums){
        //cout << a  << " ^ " << x <<  " = " << (a ^ x) <<  "\n";
        a = a ^ x;
    }
    return a;
    }
};

int main(){
    Solution s;
    vector<int> t = { 4,1,2,1,2 };
    s.singleNumber(t);

    return 0;
}