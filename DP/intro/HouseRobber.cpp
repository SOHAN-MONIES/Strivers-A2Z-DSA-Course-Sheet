// URL: https://leetcode.com/problems/house-robber/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: House Robber (Dynamic Programming)

Problem:
- You are given an array `nums` where each element represents the amount of money in a house.
- You cannot rob two adjacent houses.
- Return the maximum amount of money you can rob.

-------------------------------------------------
1️⃣ Recursive with Memoization (Top-Down):

Steps:
1. Define a helper function `helper(idx, nums, dp)` that returns the max money till index `idx`.
2. Base cases:
   - If idx == 0 → return nums[0]
   - If idx == 1 → return max(nums[0], nums[1])
3. If dp[idx] is already computed, return dp[idx].
4. Recurrence relation:
   - pick = nums[idx] + helper(idx - 2, nums, dp)
   - not_pick = helper(idx - 1, nums, dp)
   - dp[idx] = max(pick, not_pick)
5. Return dp[n-1].

Time Complexity: O(n)
Space Complexity: O(n) recursion stack + O(n) dp array

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up):

Steps:
1. Create dp array of size n.
2. Initialize dp[0] = nums[0].
3. For i = 1 to n-1:
   - pick = nums[i]
   - if (i > 1) pick += dp[i-2]
   - not_pick = dp[i-1]
   - dp[i] = max(pick, not_pick)
4. Return dp[n-1].

Time Complexity: O(n)
Space Complexity: O(n)

-------------------------------------------------
3️⃣ Space Optimized Iterative:

Steps:
1. Initialize prev2 = 0, prev1 = nums[0].
2. For i = 1 to n-1:
   - pick = nums[i] + prev2
   - not_pick = prev1
   - curr = max(pick, not_pick)
   - Update: prev2 = prev1, prev1 = curr
3. Return prev1.

Time Complexity: O(n)
Space Complexity: O(1)

-------------------------------------------------
✅ Intuition:
- Each house decision depends only on the previous two houses:
  - If you rob this house, skip the previous one.
  - If you skip this house, take the previous total.
- This naturally forms a DP recurrence similar to Fibonacci,
  but with added values (money) in each step.

*/

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