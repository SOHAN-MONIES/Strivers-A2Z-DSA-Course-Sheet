// URL: https://www.geeksforgeeks.org/problems/smallest-divisor/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool ispossible(vector<int> &nums, int threshold, int m)
{
    int sum = 0;
    for (auto num : nums)
    {
        sum += ceil((double)num / m); // make sure this is double
    }
    return sum <= threshold;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int l = 1;
    int h = *max_element(nums.begin(), nums.end());
    int ans = -1;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (ispossible(nums, threshold, m))
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
    vector<int> v1 = {2, 3, 7, 4, 10};
    cout << smallestDivisor(v1, 5);
    return 0;
}