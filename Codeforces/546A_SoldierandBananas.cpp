#include <bits/stdc++.h>

using namespace std;
// A soldier wants to buy w bananas in the shop.
// He has to pay k dollars for the first banana, 2k dollars for the second one and so on (in other words,
// he has to pay i·k dollars for the i-th banana).
// He has n dollars. How many dollars does he have to borrow from his friend soldier to buy w bananas?

int main()
{
    int k, n, w;
    int cost = 0;
    int borrow;

    cin >> k >> n >> w;

    for (int i = 1; i <= w; i++)
        cost += i * k;

    if (cost <= n)
        cout << 0;
    else
        cout << (cost - n);
    return 0;
}