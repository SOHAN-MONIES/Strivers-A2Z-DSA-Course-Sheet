#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    pair<int, int> p1;
    int n = a.size();
    int l = 0;
    int h = n - 1;
    int ans = n;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (a[m] <= x)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    int n1 = a.size();
    int l1 = 0;
    int h1 = n1 - 1;
    int ans1 = n1;
    while (l1 <= h1)
    {
        int m1 = (l1 + h1) / 2;
        if (a[m1] >= x)
        {
            ans1 = m1;
            h1 = m1 - 1;
        }
        else
        {
            l1 = m1 + 1;
        }
    }
    p1.first = ans;
    p1.second = ans1;
    return p1;
}