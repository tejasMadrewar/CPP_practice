#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countElements(vector<int> &arr)
    {
        int result = 0;
        map<int, int> m;
        // count freq of numbers
        for (auto i : arr)
            m[i]++;

        // find result
        for (auto i : m)
        {
            if (m.find(i.first + 1) != m.end())
            {
                result = result + i.second;
            }
        }
        return result;
    }
};


//class Solution {
//public:
//    int countElements(vector<int> &arr)
//    {
//        int result = 0;
//        int n = arr.size();
//        sort(arr.begin(), arr.end());
//
//            int flag = 0;
//        for (int i = 0; i < n; i++) {
//
//            for (int j = i + 1; j < n; j++)
//                if ((arr[j] - arr[i] == 1) && (flag == 0)) {
//                    ++result;
//                    flag = 1;
//                }
//            flag = 0;
//        }
//        return result;
//    }
//};

int main(){
    Solution s;

    vector<int> v = {1,2,3};
    if(s.countElements(v) == 2) cout << "PASS\n"; else cout << "FAIL\n";

    v = {1,1,3,3,5,5,7,7};
    if(s.countElements(v) == 0) cout << "PASS\n"; else cout << "FAIL\n";

    v = {1,3,2,3,5,0};
    if(s.countElements(v) == 3) cout << "PASS\n"; else cout << "FAIL\n";

    v = {1,1,2,2};
    if(s.countElements(v) == 2) cout << "PASS\n"; else cout << "FAIL\n";

    return 0;
}