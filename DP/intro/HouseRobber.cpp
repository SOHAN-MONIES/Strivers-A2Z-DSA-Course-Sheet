// URL: https://leetcode.com/problems/house-robber/
#include <bits/stdc++.h>
using namespace std;
int helper(int idx, vector<int> &nums, vector<int> &dp)
{
    if (idx == 0)
    {
        return nums[idx];
    }
    if (idx == 1)
    {
        return max(nums[idx], nums[idx - 1]);
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    int pick = nums[idx] + helper(idx - 2, nums, dp);
    int n_pick = helper(idx - 1, nums, dp);
    return dp[idx] = max(pick, n_pick);
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return helper(n - 1, nums, dp);
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums);
    return 0;
}