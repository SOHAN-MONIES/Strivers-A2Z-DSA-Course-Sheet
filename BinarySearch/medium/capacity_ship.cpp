// URL: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isPossible(vector<int> &weights, int days, int m)
{
    int load = 0;
    int day = 1;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] <= m)
        {
            load += weights[i];
        }
        else
        {
            day++;
            load = weights[i];
        }
    }
    return day <= days;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int l = *max_element(weights.begin(), weights.end());
    int h = accumulate(weights.begin(), weights.end(), 0);
    int ans = -1;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (isPossible(weights, days, m))
        {
            ans = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}

int main()
{

    return 0;
}