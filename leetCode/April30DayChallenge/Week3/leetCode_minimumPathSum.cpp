#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    void printVec(vector<vector<int>>& grid){
        int x = grid.size(); 
        int y = grid[0].size();
        
        // dynamic programming
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "-----------------------\n";
        return;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int x = grid.size(); 
        if(x == 0) return 0;
        int y = grid[0].size();
        
        // dynamic programming
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                //cout << i << "," << j << "\n";
                //printVec(grid);

                // if both i and j positive
                if (i > 0 and j > 0)
                {
                    grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);   // add min between up and left cell
                }
                // if i == 0 and j is positive    // for first row
                else if (i == 0 and j > 0)
                {
                    grid[i][j] += grid[i][j - 1];   // add previous row element
                }
                // if i positive and  j = 0    // for first column
                else if (i > 0 and j == 0)
                {
                    grid[i][j] += grid[i - 1][j]; // add pervious column element
                }
            }
        }
        //printVec(grid);
        return grid[x-1][y-1];

    }

};

int main(){
    Solution s;

    vector<vector<int>> v = 
    {
  {1,3,1},
  {1,5,1},
  {4,2,1}
};

    if(s.minPathSum(v) == 7) cout << "PASS\n"; else cout << "FAIL\n";

    return 0;
}