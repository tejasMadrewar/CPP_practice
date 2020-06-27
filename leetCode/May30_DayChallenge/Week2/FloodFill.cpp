#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";

//An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
//
//Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill,
//  and a pixel value newColor, "flood fill" the image.
//
//To perform a "flood fill", consider the starting pixel,
// plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel,
// plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel),
//  and so on. Replace the color of all of the aforementioned pixels with the newColor.
//
//At the end, return the modified image
//Note:
//
//The length of image and image[0] will be in the range [1, 50].
//The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
//The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

void printImage(vector<vector<int>>& image){
    for(auto i : image){
        for(auto j:i){
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "-------------------------\n";
}

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int m = image.size();
        int n = image[0].size();

        int oldColor = image[sr][sc];
        queue<pair<int, int>> q;
        vector<pair<int, int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        q.push({sr, sc});
        pair<int, int> a;

        while (!q.empty())
        {
            image[q.front().first][q.front().second] = newColor;
            for (auto i : direction)
            {
                int a = q.front().first + i.first;
                int b = q.front().second + i.second;
                if (a >= 0 && a < m && b >= 0 && b < n)
                    if (image[a][b] == oldColor)
                        q.push({a, b});
            }
            q.pop();

        }
        return image;
    }
};

class Solution1 {
public:
    void floodFillRec(vector<vector<int>> &image, int sr, int sc, int startingColor, int newColor)
    {
        if (sr == image.size() || sr < 0 || sc < 0 || sc == image[sr].size() || image[sr][sc] != startingColor)
            return;
        image[sr][sc] = newColor;
        floodFillRec(image, sr + 1, sc, startingColor, newColor);
        floodFillRec(image, sr - 1, sc, startingColor, newColor);
        floodFillRec(image, sr, sc + 1, startingColor, newColor);
        floodFillRec(image, sr, sc - 1, startingColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int startingColor = image[sr][sc];
        image[sr][sc] = newColor;
        if (startingColor == newColor)
            return image;
        floodFillRec(image, sr + 1, sc, startingColor, newColor);
        floodFillRec(image, sr - 1, sc, startingColor, newColor);
        floodFillRec(image, sr, sc + 1, startingColor, newColor);
        floodFillRec(image, sr, sc - 1, startingColor, newColor);
        return image;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v;
    vector<vector<int>> ans;
    v =   {{1,1,1},{1,1,0},{1,0,1}};
    ans = {{2,2,2},{2,2,0},{2,0,1}};

    if(s.floodFill(v,1,1,2) == ans) PRINT

    v = {{0,0,0},{0,0,0}};
    ans = {{2,2,2},{2,2,2}};
    if(s.floodFill(v,0,0,2) == ans) PRINT

    return 0;
}