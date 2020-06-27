#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

//We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
//(Here, the distance between two points on a plane is the Euclidean distance.)
//You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        int n = points.size();
        vector<long> distance(n);
        vector<int> index(n);
        vector<vector<int>> results(K);

        long long temp;

        for (int i = 0; i < n; ++i)
        {
            temp = (long long)(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            distance[i] = temp;
            index[i] = i;
        }

        auto comp = [&](int &a, int &b) -> bool { return distance[a] < distance[b]; };

        nth_element(index.begin(), index.begin() + K, index.end(), comp);

        for (int i = 0; i < K; i++)
        {
            //cout << points[index[i]][0] << " " << points[index[i]][1] << "\n";
            results[i] = points[index[i]];
        }

        return results;
    }
};

class Solution1
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {

        auto comp = [&](const vector<int> &a, const vector<int> &b) -> bool { 
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]); };

        nth_element(points.begin(), points.begin() + K, points.end(), comp);
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

int main(){

    Solution1 s;

    vector<vector<int>> v;
    vector<vector<int>> ans;
    vector<vector<int>> ans1;

    ans = {{-2,2}};
    v = {{1,3},{-2,2}};

    if(s.kClosest(v,1) == ans) PRINT

    v = {{3, 3}, {5, -1}, {-2, 4}};
    ans = {{3, 3}, {-2, 4}};
    ans1 = {{-2, 4}, {3, 3}};

    if(s.kClosest(v,2) == ans or s.kClosest(v,2) == ans1) PRINT


return 0;

}