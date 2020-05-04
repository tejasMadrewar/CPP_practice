#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void printVec( vector<vector<int>> t){
        cout << "-----------------------------\n";
        for (int i = 0; i < t.size(); i++)
        {
            for(int j = 0; j < t.at(i).size(); j++){
                cout << t[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "-----------------------------\n";
        

    }

    void markIsland(vector<vector<int>> &t,vector<vector<char>> &c, int i, int j)
    {

        // get size of map
        int x = t.size();
        int y = t[0].size();

        // check range, water, pervious visited then return
        if(i < 0 or j < 0 or i >= x or j >= y or c[i][j] == '0' or t[i][j] == -1) return;

        // mark as visited
        t[i][j] = -1;
        //cout << "*" << i << " " << j << "\n";

        // up down left right cell addition
        int changeX[4] = {0,-1,1,0};
        int changeY[4] = {-1,0,0,1};

        // iterate through all neighbour
        for(int d  = 0; d < 4; d++){
            markIsland(t, c, i + changeX[d], j + changeY[d]);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // 1 is land and 0 is water
        if(grid.size() ==0) return 0;
        vector<vector<int>> t(grid.size(),vector<int>(grid[0].size(), -2));
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.at(i).size(); j++){

                if(grid[i][j] == '1' && t[i][j] == -2){
                    bool oldland = false;

                    if (i + 1 < t.size())
                        if (t[i + 1][j] == -1)
                        oldland = true;

                    if (j + 1 < t.at(i).size())
                        if (t[i][j + 1] == -1)
                        oldland = true;

                    if (i - 1 > 0)
                        if (t[i - 1][j] == -1)
                        oldland = true;

                    if (j - 1 > 0)
                        if (t[i][j - 1] == -1)
                        oldland = true;

                    if (oldland == false) {
                        count++;

                        //printVec(t);
                        markIsland(t,grid,i,j);
                        t[i][j] = -1;
                        //printVec(t);
                        //cout << i << " " << j << "\n";
                        //cout << count << "\n";
                    }
                }
            }
        }
        return count;
    }
};

int main(){
    Solution s;
//    vector<vector<char>> v = 
//                            {
//                            {'1','1','1','1','0'},
//                            {'1','1','0','1','0'},
//                            {'1','1','0','0','0'},
//                            {'0','0','0','0','0'}};
//
//    vector<vector<char>> v = {
//    {'1','1','0','0','0'},
//    {'1','1','0','0','0'},
//    {'0','0','1','0','0'},
//    {'0','0','0','1','1'}
//};

//    vector<vector<char>> v = {
//{ '1','1','1'},
//{ '0','1','0'},
//{ '1','1','1'}};

vector<vector<char>> v = 
{
{ '1','0','1','1','1' },
{ '1','0','1','0','1' },
{ '1','1','1','0','1' }
};

    cout << s.numIslands(v);


    return 0;
}