#include <bits/stdc++.h>

using namespace std;
//
// You are given a rectangular board of M × N squares. Also you are given an unlimited number of standard domino pieces of 2 × 1 squares. You are allowed to rotate the pieces. You are asked to place as many dominoes as possible on the board so as to meet the following conditions:
//
// 1. Each domino completely covers two squares.
//
// 2. No two dominoes overlap.
//
// 3. Each domino lies entirely inside the board. It is allowed to touch the edges of the board.
//
// Find the maximum number of dominoes, which can be placed under these restrictions
//
// 2 4
// -> 4
// 3 3
// -> 4

int main()
{
    int l, w;
    cin >> l >> w;

    // either l direction or w direction

    int t1 = ((l / 2) * w) + ((w / 2) * (l % 2));
    int t2 = ((w / 2) * l) + ((l / 2) * (w % 2));
    cout << max(t1, t2);
    return 0;
}