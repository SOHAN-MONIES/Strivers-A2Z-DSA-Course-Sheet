// URL: https://leetcode.com/problems/sqrtx/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int mySqrt(int x)
{
    int l = 1;
    int h = x;
    int ans = 0;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (m <= x / m)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    return ans;
}

int main()
{
    cout << mySqrt(17);
    return 0;
}