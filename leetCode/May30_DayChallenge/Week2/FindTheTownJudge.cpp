#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";
//In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.
//
//If the town judge exists, then:
//
//The town judge trusts nobody.
//Everybody (except for the town judge) trusts the town judge.
//There is exactly one person that satisfies properties 1 and 2.
//You are given trust, an array of pairs trust[i] = [a, b] 
//representing that the person labelled a trusts the person labelled b.
//
//If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        //vector<vector<int>> v(N,vector<int>(N));
        //for(auto i:trust){
        //    v[i[0]-1][i[1]-1] = 1;
        //}

        //// member
        //for (int i = 0; i < N; i++)
        //{
        //    int flag = 1;
        //    // other member
        //    for (int j = 0; j < N && flag == 1; j++)
        //    {
        //        if(i == j)
        //            continue;
        //        // member trust other member
        //        if(v[i][j] == 1)
        //            flag = 0;
        //        // other member not trust  member
        //        if(v[j][i] == 0)
        //            flag = 0;
        //    }
        //    if(flag == 1)
        //        return i+1;
        //}

        //return -1;

        vector<pair<int, int>> v(N + 1, {0, 0});

        for (auto i : trust)
        {
            v[i[0]].first++;
            v[i[1]].second++;
        }

        for (int i = 1; i < N + 1; i++)
        {
            if (v[i].first == 0 && v[i].second == (N - 1))
                return i;
        }

        return -1;
    }
};


int main(){
    Solution s;
    vector<vector<int>> v;

    v = { { 1,2 } };
    if(s.findJudge(2,v) == 2) PRINT

    v = { { 1,3 },{ 2,3 } };
    if(s.findJudge(3,v) == 3) PRINT

    v = { { 1,3 },{ 2,3 },{ 3,1 } };
    if(s.findJudge(3,v) == -1) PRINT

    v = { { 1,2 },{ 2,3 } };
    if(s.findJudge(3,v) == -1) PRINT

    v = { { 1,3 },{ 1,4 },{ 2,3 },{ 2,4 },{ 4,3 } };
    if(s.findJudge(4,v) == 3) PRINT

    return 0;
}