#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string,vector<string>> m;

        for (int i = 0; i < strs.size(); i++)
        {
            string temp(strs[i]);
            sort(temp.begin(), temp.end());

            if (m.find(temp) == m.end())
            {
                vector<string> temp_vec;
                temp_vec.push_back(strs[i]);
                m.insert(make_pair(temp, temp_vec));
            }
            else
            {
                m.find(temp)->second.push_back(strs[i]);
            }
        }

        for(auto i:m){
            result.push_back(i.second);
        }

        return result;
    }
};

int main(){
    Solution s;
    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ss = s.groupAnagrams(v);

    for(auto a:ss){
        for(auto aa:a){
            cout << aa << " ";
        }
        cout << "\n\n";
    }

    return 0;
}