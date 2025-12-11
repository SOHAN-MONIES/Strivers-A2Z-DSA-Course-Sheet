// URL:https://leetcode.com/problems/partition-equal-subset-sum/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Partition Equal Subset Sum (Using Subset Sum DP)

Problem:
Given an array `nums`, determine whether it can be partitioned into TWO subsets
such that their sums are equal.

Key Idea:
If total array sum = S:
- If S is odd → impossible → return false
- Otherwise, we check if there exists a subset with sum = S/2
This becomes a Subset Sum problem.

-------------------------------------------------
1️⃣ Logic:

1. Compute total sum of array.
2. If sum is odd → return false.
3. Target = sum / 2.
4. Run subset-sum DP to check if any subset equals target.

-------------------------------------------------
2️⃣ Subset Sum Check (Reusing DP Logic)

We call subsetSum(arr, target):

Base Cases:
- If target == 0 → true
- If only first element:
      return (arr[0] == target)

Transition:
For each index i and sum t:
    not_take = dp[i-1][t]
    take = dp[i-1][t - arr[i]] if arr[i] ≤ t
    dp[i][t] = take OR not_take

Final Answer:
dp[n-1][target] → true or false

-------------------------------------------------
🕒 Time Complexity: O(n × sum/2)
🧠 Space Complexity:
- O(n × sum/2) for full DP
- O(sum/2) for space-optimized version

-------------------------------------------------
🎯 Intuition:
Partitioning into two equal subsets is only possible if we can find ONE subset
whose sum is exactly half the total sum.
That’s why this reduces perfectly to Subset Sum DP.
-------------------------------------------------
*/

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }
    if (ind == 0)
    {
        return arr[ind] == target;
    }
    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }
    bool not_take = f(ind - 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target)
    {
        take = f(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = take || not_take;
}
bool isSubsetSum_Memoization(vector<int> &arr, int sum)
{ // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return f(n - 1, sum, arr, dp);
}
bool isSubsetSum_Tabulation(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= sum)
    {
        dp[0][arr[0]] = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= sum; target++)
        {
            bool not_take = dp[i - 1][target];
            bool take = false;
            if (arr[i] <= target)
            {
                take = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = take || not_take;
        }
    }
    return dp[n - 1][sum];
}
bool f(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<int> prev(sum + 1, 0);
    prev[0] = true;
    if (arr[0] <= sum)
    {
        prev[arr[0]] = true;
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(sum + 1, 0);
        curr[0] = true;
        for (int target = 1; target <= sum; target++)
        {
            bool not_take = prev[target];
            bool take = false;
            if (arr[i] <= target)
            {
                take = prev[target - arr[i]];
            }
            curr[target] = take || not_take;
        }
        prev = curr;
    }
    return prev[sum];
}
bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
    {
        return false;
    }
    return f(nums, sum / 2);
}
int main()
{

    return 0;
}