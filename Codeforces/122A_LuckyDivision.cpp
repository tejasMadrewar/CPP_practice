#include <bits/stdc++.h>

using namespace std;

// Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers
// whose decimal representation contains only the lucky digits 4 and 7.
// For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.
// 1A, 28B

int main()
{
    int n;
    cin >> n;
    bool flag = 0;
    int arr[12] = {4, 7, 47, 74, 44, 444, 447, 474, 477, 777, 774, 744};
    for (int i = 0; i < 12; i++)
    {
        if (n % arr[i] == 0)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}