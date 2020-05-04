#include<bits/stdc++.h>

using namespace std;

// Leftmost Column with at Least a One

// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
class BinaryMatrix {
  public:
    vector<vector<int>> values;
    int get(int x, int y){
        return values.at(x).at(y);
    }

    int set(vector<vector<int>> a){
        values = a;
    }
    vector<int> dimensions(){
        int n = values.size();
        int m = values[0].size();

        return {n,m};
    }
};

class Solution
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> v;
        v = binaryMatrix.dimensions();
        int n = v[0];
        int m = v[1];
        int val;
        // make default value to -1
        int curr = -1;

        // set initial values
        int i = 0;
        int j = m - 1;
        while (i <= n - 1 && j >= 0)
        {
            // get value
            val = binaryMatrix.get(i, j);

            // if value is zero
            if (val == 0)
                // increase the row
                i++;
            else
            {
                // IMPORTANT

                // if value is 1
                // save current column
                curr = j;
                // decrement the column
                j--;
            }
        }
        // return last saved column with value 1
        return curr;
    }
};

int main(){

    vector<vector<int>> a;
    BinaryMatrix b;
    Solution s;

    a = { { 0,0,0,1 },{ 0,0,1,1 },{ 0,1,1,1 } };
    b.set(a);
    if(s.leftMostColumnWithOne(b) == 1) cout << "PASS\n"; else cout << "FAIL\n";

    a = { { 0,0 },{ 0,0 } };
    b.set(a);
    if(s.leftMostColumnWithOne(b) == -1) cout << "PASS\n"; else cout << "FAIL\n";


    a = { { 0,0 },{ 0,1 } };
    b.set(a);
    if(s.leftMostColumnWithOne(b) == 1) cout << "PASS\n"; else cout << "FAIL\n";

    return 0;
}