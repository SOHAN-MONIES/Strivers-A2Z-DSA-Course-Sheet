#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int helper(int idx, vector<int> &height, vector<int> &dp)
{
    int n = height.size();

    // base case: reached last stone
    if (idx == n - 1)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    // Option 1: jump to next stone
    int one = abs(height[idx] - height[idx + 1]) + helper(idx + 1, height, dp);

    // Option 2: jump two stones ahead (if possible)
    int two = INT_MAX;
    if (idx + 2 < n)
        two = abs(height[idx] - height[idx + 2]) + helper(idx + 2, height, dp);

    return dp[idx] = min(one, two);
}

int minCost(vector<int> &height)
{
    int n = height.size();
    vector<int> dp(n, -1);
    return helper(0, height, dp);
}
int main()
{
    vector<int> heights = {10, 20, 30, 10};
    cout << minCost(heights);
    return 0;
}