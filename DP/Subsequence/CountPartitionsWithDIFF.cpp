// URL:https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
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

int generate(vector<int> &arr, int i, int target, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (target == 0)
            return (arr[0] == 0 ? 2 : 1);

        return (arr[0] == target ? 1 : 0);
    }
    if (dp[i][target] != -1)
    {
        return dp[i][target];
    }
    int not_take = generate(arr, i - 1, target, dp);
    int take = 0;
    if (arr[i] <= target)
    {
        take = generate(arr, i - 1, target - arr[i], dp);
    }

    return dp[i][target] = take + not_take;
}

int perfectSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return generate(arr, n - 1, target, dp);
}
int countPartitions(vector<int> &arr, int diff)
{
    // Code here
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum - diff < 0 || (sum - diff) % 2 == 1)
        return false;
    return perfectSum(arr, (sum - diff) / 2);
}
int main()
{

    return 0;
}