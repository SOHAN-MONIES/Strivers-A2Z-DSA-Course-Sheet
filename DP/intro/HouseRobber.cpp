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
        return max(nums[idx], nums[0]);
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

int rob_tb(vector<int> nums)
{
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int pick, n_pick;
    for (int i = 1; i < nums.size(); i++)
    {
        pick = nums[i];

        if (i > 1)
        {
            pick += dp[i - 2];
        }
        n_pick = dp[i - 1];
        dp[i] = max(pick, n_pick);
    }
    return dp[nums.size() - 1];
}
int rob_optimized(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int prev2 = 0, prev1 = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int pick = nums[i] + prev2;
        int n_pick = prev1;
        int curr = max(pick, n_pick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    vector<int> nums = {2, 3, 2};
    cout << rob_tb(nums) << endl;
    cout << rob(nums) << " " << rob_optimized(nums);
    return 0;
}