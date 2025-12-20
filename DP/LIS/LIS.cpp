// URL:https://leetcode.com/problems/longest-increasing-subsequence/description/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Longest Increasing Subsequence (Dynamic Programming)

Problem:
Given an array `nums`, find the length of the **Longest Increasing Subsequence (LIS)**.
A subsequence is increasing if:
    nums[i1] < nums[i2] < nums[i3] < ...

-------------------------------------------------
State Definition:

f(idx, prev_idx):
- idx       → current index we are deciding on
- prev_idx  → index of previously taken element in the subsequence
              (or n if no element has been taken yet)

Meaning:
Maximum LIS length starting from index `idx`
given that the previous chosen index is `prev_idx`.

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Base Case:
- If idx == n → no elements left → return 0

Memoization:
- If dp[idx][prev_idx] is already computed → return it

Choices:
1. Do NOT take nums[idx]
      len1 = f(idx+1, prev_idx)

2. Take nums[idx] (only if valid):
      Allowed if:
          prev_idx == n  OR  nums[idx] > nums[prev_idx]
      len2 = 1 + f(idx+1, idx)

Transition:
dp[idx][prev_idx] = max(len1, len2)

Initial Call:
f(0, n)

Time Complexity: O(n²)
Space Complexity: O(n²) + recursion stack

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up DP)

DP Table:
dp[idx][prev_idx] = LIS starting at idx with previous index prev_idx

Table Size:
(n+1) × (n+1)

Initialization:
- dp[n][*] = 0 → no elements left

Filling Order:
- idx from n-1 → 0
- prev_idx from n → 0

Transition:
len1 = dp[idx+1][prev_idx]
len2 = 0
If prev_idx == n OR nums[idx] > nums[prev_idx]:
    len2 = 1 + dp[idx+1][idx]

dp[idx][prev_idx] = max(len1, len2)

Final Answer:
dp[0][n]

Time Complexity: O(n²)
Space Complexity: O(n²)

-------------------------------------------------
3️⃣ Space Optimized DP

Observation:
dp[idx] depends only on dp[idx+1]

Use:
- next[] → dp[idx+1][*]
- curr[] → dp[idx][*]

Steps:
1. Initialize next[] with 0
2. Iterate idx from n-1 → 0
3. For each prev_idx from n → 0:
      len1 = next[prev_idx]
      len2 = 0
      If prev_idx == n OR nums[idx] > nums[prev_idx]:
          len2 = 1 + next[idx]
      curr[prev_idx] = max(len1, len2)
4. next = curr

Final Answer:
next[n]

Time Complexity: O(n²)
Space Complexity: O(n)

-------------------------------------------------
🎯 Intuition:
At every index, we either:
- Skip the element, or
- Take it (only if it keeps the sequence increasing)

The `prev_idx` helps enforce the increasing condition.
The DP ensures all subsequences are explored efficiently.

-------------------------------------------------
*/
int f(int idx, int prev_idx, vector<int> &arr, vector<vector<int>> &dp)
{
    if (idx == arr.size())
    {
        return 0;
    }
    if (dp[idx][prev_idx] != -1)
    {
        return dp[idx][prev_idx];
    }
    int len1 = f(idx + 1, prev_idx, arr, dp);
    int len2 = 0;
    if (prev_idx == arr.size() || arr[idx] > arr[prev_idx])
    {
        len2 = 1 + f(idx + 1, idx, arr, dp);
    }
    return dp[idx][prev_idx] = max(len1, len2);
}
int lengthOfLIS_Memoization(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(0, n, nums, dp);
}
int lengthOfLIS_TAB(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev_idx = n; prev_idx >= 0; prev_idx--)
        {
            int len1 = dp[idx + 1][prev_idx];
            int len2 = 0;
            if (prev_idx == nums.size() || nums[idx] > nums[prev_idx])
            {
                len2 = 1 + dp[idx + 1][idx];
            }
            dp[idx][prev_idx] = max(len1, len2);
        }
    }
    return dp[0][n];
}
int lengthOfLIS_SPACE(vector<int> &nums)
{
    int n = nums.size();
    vector<int> next(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev_idx = n; prev_idx >= 0; prev_idx--)
        {
            int len1 = next[prev_idx];
            int len2 = 0;
            if (prev_idx == nums.size() || nums[idx] > nums[prev_idx])
            {
                len2 = 1 + next[idx];
            }
            curr[prev_idx] = max(len1, len2);
        }
        next = curr;
    }
    return next[n];
}
// optimized
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] > nums[prev])
            {
                dp[i] = max(1 + dp[prev], dp[i]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << lengthOfLIS(arr);
    return 0;
}