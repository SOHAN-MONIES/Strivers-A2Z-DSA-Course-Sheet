// URL: https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool ispossible(vector<int> &bloomDay, int m, int k, int mid)
{
    int cnt = 0;
    int a = 0;
    for (auto num : bloomDay)
    {
        if (mid >= num)
        {
            cnt++;
        }
        else
        {
            a += cnt / k;
            cnt = 0;
        }
    }
    a += cnt / k;  // you are checking valid number of bouqket using else if there is valid sequence at end , the number skips , hence add after loop [if its not valid cnt=0 so no problem]
    return a >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int l = *min_element(bloomDay.begin(), bloomDay.end());
    int h = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (ispossible(bloomDay, m, k, mid))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v1 = {7, 7, 7, 7, 12, 7, 7};
    cout << minDays(v1,2,3);
    return 0;
}