// URL:https://leetcode.com/problems/koko-eating-bananas/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long findtotalhrs(vector<int> &piles, int a)
{
    long long totalhours = 0;
    for (auto num : piles)
    {
        totalhours += ceil((double)num / a); // make sure this is double
    }
    return totalhours;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int hm = *max_element(piles.begin(), piles.end());
    int l = 1;
    int ans = -1;
    while (l <= hm)
    {
        int m = l + (hm - l) / 2;
        if (findtotalhrs(piles, m) > h)
        {
            l = m + 1;
        }
        else
        {
            ans = m;
            hm = m - 1;
        }
    }
    return ans;
}

// int minEatingSpeed(vector<int> &piles, int h)
// {
//     int maxh = *max_element(piles.begin(), piles.end());
//     for (int i = 1; i <=maxh; i++)
//     {
//         if (findtotalhrs(piles, i) <= h)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

int main()
{
    vector<int> v1 = {3, 6, 7, 11};
    cout << minEatingSpeed(v1, 8);
    return 0;
}