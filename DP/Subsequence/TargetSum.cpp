// URL:http://geeksforgeeks.org/problems/target-sum-1626326450/1
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Subset Sum (Dynamic Programming)

Problem:
Given an array of integers and a value `sum`, determine if there exists a subset
whose elements add up exactly to `sum`.

Goal:
Return true if such a subset exists, otherwise false.

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Function f(ind, target):
- Base cases:
    - If target == 0 → return true (empty subset makes 0)
    - If ind == 0 → return (arr[0] == target)
- If already computed → return dp[ind][target]
- Choices:
    not_take = f(ind-1, target)
    take = false
    if arr[ind] <= target:
         take = f(ind-1, target - arr[ind])

Return:
    dp[ind][target] = take OR not_take

Time Complexity: O(n × sum)
Space Complexity: O(n × sum) + recursion stack

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up DP)

Steps:
1. Create dp[n][sum+1] initialized to false
2. Base initialization:
      dp[i][0] = true for all i
      dp[0][arr[0]] = true (if valid)
3. Fill table:
      For each i from 1 to n-1:
        For each target from 1 to sum:
            not_take = dp[i-1][target]
            take = dp[i-1][target-arr[i]] if arr[i] ≤ target
            dp[i][target] = take OR not_take
4. Result = dp[n-1][sum]

Time Complexity: O(n × sum)
Space Complexity: O(n × sum)

-------------------------------------------------
3️⃣ Space Optimized DP

Idea:
Use only `prev[]` and `curr[]` instead of full matrix.

Steps:
1. prev[0] = true (0 sum always possible)
2. If arr[0] <= sum → prev[arr[0]] = true
3. For every element:
        For each target:
             curr[target] = prev[target] OR prev[target-arr[i]]
4. prev = curr

Final answer: prev[sum]

Time Complexity: O(n × sum)
Space Complexity: O(sum)

-------------------------------------------------
🎯 Intuition:
At every index, we decide whether to include the current element or skip it.
The DP table stores whether each sum is achievable up to that index.
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
bool isSubsetSum(vector<int> &arr, int sum)
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

int main()
{

    return 0;
}