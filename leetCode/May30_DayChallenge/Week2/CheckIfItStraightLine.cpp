#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int n = coordinates.size();
        if (n == 2)
            return true;

        double slope = ((double)coordinates[0][1] - coordinates[1][1]) / (coordinates[0][0] - coordinates[1][0]);
        for (int i = 1; i < n; i++)
            if (slope != ((double)coordinates[0][1] - coordinates[i][1]) / (coordinates[0][0] - coordinates[i][0]))
                return false;

        return true;
    }
};


int main(){
    Solution s;
    vector<vector<int>> v;
    v = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    if(s.checkStraightLine(v) == true) PRINT

    v = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
    if(s.checkStraightLine(v) == false) PRINT
}