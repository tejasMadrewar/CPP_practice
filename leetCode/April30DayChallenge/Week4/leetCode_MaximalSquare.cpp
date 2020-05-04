#include<bits/stdc++.h>

using namespace std;


// find the largest square containing only 1's and return its area.

//class Solution {
//    private:
//    int getArea(vector<vector<int>>& mat, int a, int b, int size){
//
//        int area = 0;
//        for (int i = a; i < a + size && i < mat.size(); i++)
//        {
//            for (int j = b; j < b + size && j < mat[i].size(); j++)
//            {
//                if(mat[i][j] == 0) return area;
//                area = area + 1;
//            }
//        }
//        return area;
//    }
//public:
//    int maximalSquare(vector<vector<char>>& matrix) {
//        vector<vector<int>> vi;
//        for(auto i:matrix){
//            vector<int> v;
//            for(auto j:i){
//                if(j == '1')
//                    v.push_back(1);
//                else
//                    v.push_back(0);
//            }
//            vi.push_back(v);
//            v = {};
//        }
//
//        // find
//        int area = 0;
//        for(int i = 0; i < matrix.size(); i++){
//            for(int j =0; j < matrix[j].size();j++){
//                if(matrix[i][j] == '0')
//                    continue;
//                int size = 1;
//                int a = getArea(vi,i,j,size);
//                while(a == size*size){
//                    size++;
//                    area = max(area,a);
//                    a = getArea(vi,i,j,size);
//                }
//
//            }
//        }
//
//        cout << area << "\n";
//        return area;
//    }
//};


class Solution {
public:
    // DP
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxSide = 0;
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        vector<vector<int>> dpTable(n, vector<int>(m, 0));

        // setup first col
        for (int i = 0; i < n; i++) {
            dpTable[i][0] = (matrix[i][0] == '1' ? 1 : 0);
            maxSide = max(maxSide, dpTable[i][0]);
        }
        // setup first row
        for (int i = 0; i < m; i++) {
            dpTable[0][i] = (matrix[0][i] == '1' ? 1 : 0);
            maxSide = max(maxSide, dpTable[0][i]);
        }

        // iterate thorugh remaining cell
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                // if zero then 0
                // else
                // min [i-1][j-1], [i-1][j] ,[i][j-1]  + 1
                //    1 1 * *
                //    1 2 * *
                //    * * * *

                dpTable[i][j] = (matrix[i][j] == '0' ? 0 : min({dpTable[i - 1][j - 1], dpTable[i - 1][j], dpTable[i][j - 1]}) + 1);
                maxSide = max(maxSide, dpTable[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << dpTable[i][j] << ", ";
            cout << "\n";
        }
        return maxSide * maxSide;
    }
};

int main(){
    Solution s;
    vector<vector<char>> v =
    {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    //{
    //    {'1','0','1','0','0'},
    //    {'1','0','1','1','1'},
    //    {'1','1','1','1','1'},
    //    {'1','0','0','1','0'}
    //};
    if(s.maximalSquare(v) == 4) cout << "PASS\n"; else cout << "FAIL\n";

    return 0;
}