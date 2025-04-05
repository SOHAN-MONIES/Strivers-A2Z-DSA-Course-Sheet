// URL: https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int nthRoot(int n, int m)
{
    int l = 1;
    int h = m;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (pow(mid, n) == m)
        {
            return mid;
        }
        if (pow(mid, n) > m)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    cout << nthRoot(6, 1000000);
    return 0;
}