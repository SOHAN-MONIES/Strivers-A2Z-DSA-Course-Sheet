// URL:https://leetcode.com/problems/burst-balloons/description/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Burst Balloons (Partition Dynamic Programming)

Problem:
You are given `nums` representing balloons.
When you burst balloon `k`, you gain:
    nums[left] * nums[k] * nums[right]
where `left` and `right` are the nearest unburst balloons.

Goal:
Burst all balloons to **maximize total coins**.

-------------------------------------------------
Key Observation:

Instead of thinking which balloon to burst FIRST,
we think which balloon to burst **LAST** in a range.

This converts the problem into **Partition DP**
(similar to Matrix Chain Multiplication).

-------------------------------------------------
Preprocessing:

1. Insert `1` at the beginning and end of nums
   to handle boundary balloons.
   Example:
       [3,1,5,8] → [1,3,1,5,8,1]

-------------------------------------------------
State Definition:

f(i, j):
- Maximum coins obtained by bursting balloons
  in the open interval (i, j)
- Balloons at index `i` and `j` are NOT burst yet

-------------------------------------------------
Base Case:

If i + 1 == j:
- No balloon to burst between them
- return 0

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Transition:
Try every balloon `k` such that:
    i < k < j
and assume `k` is the **last balloon** to burst.

Coins gained:
nums[i] * nums[k] * nums[j]

Total coins:
coins =
    nums[i] * nums[k] * nums[j]
  + f(i, k)
  + f(k, j)

dp[i][j] = max over all k

Memoization:
If dp[i][j] already computed → return it

-------------------------------------------------
Initial Call:
f(0, n-1)

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up DP)

DP Table:
dp[i][j] = max coins for interval (i, j)

Filling Order:
- i from n-1 → 0
- j from 0 → n-1
- only process when i + 1 < j

Transition:
Same as recursion, using dp instead of f()

Final Answer:
dp[0][n-1]

-------------------------------------------------
Time Complexity:
O(n³)
- n² states
- each state tries n partitions

-------------------------------------------------
Space Complexity:
O(n²)

-------------------------------------------------
🎯 Intuition:
- Choose the LAST balloon to burst in every range
- That guarantees neighbors are fixed
- This avoids recomputation and handles overlapping subproblems
- Same pattern as Matrix Chain Multiplication

-------------------------------------------------
*/

int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i + 1 == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    long mini = INT_MIN;
    for (int k = i + 1; k < j; k++)
    {

        long coins = nums[i] * nums[k] * nums[j] + f(i, k, nums, dp) + f(k, j, nums, dp);
        mini = max(mini, coins);
    }
    return dp[i][j] = mini;
}

int maxCoins_Memo(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, n - 1, nums, dp);
}
int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + 1 == j)
            {
                continue;
            }
            else
            {
                long mini = INT_MIN;
                for (int k = i + 1; k < j; k++)
                {

                    long coins = nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j];
                    mini = max(mini, coins);
                }
                dp[i][j] = mini;
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{

    return 0;
}