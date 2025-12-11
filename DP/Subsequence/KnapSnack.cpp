// URL:https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: 0/1 Knapsack (DP)

Problem:
You are given:
- `wt[i]`  → weight of item i
- `val[i]` → value of item i
- `W` → maximum weight capacity

Goal:
Pick items such that:
- Total weight ≤ W
- Total value is maximized
- Each item can be taken at most once (0/1)

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Function f(i, W):
- Base case:
    If i == 0:
        If wt[0] ≤ W → return val[0]
        Else return 0
- If dp[i][W] already computed → return dp[i][W]

Choices:
- not_take = f(i-1, W)
- take = val[i] + f(i-1, W - wt[i]) if wt[i] ≤ W

dp[i][W] = max(take, not_take)

Time Complexity: O(n × W)
Space Complexity: O(n × W) + recursion stack

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up DP)

Steps:
1. Create dp[n][W+1] initialized to 0
2. Base row (i=0):
       For w from wt[0] to W:
            dp[0][w] = val[0]
3. For each item i from 1..n-1:
       For each weight w from 0..W:
            not_take = dp[i-1][w]
            take     = val[i] + dp[i-1][w-wt[i]] if wt[i] ≤ w
            dp[i][w] = max(take, not_take)

Answer = dp[n-1][W]

-------------------------------------------------
3️⃣ Space Optimization (2 rows → 1 row)

Idea:
- Only need previous row, so store:
      prev[w]
      curr[w]

Transition:
curr[w] = max(prev[w], val[i] + prev[w - wt[i]])

-------------------------------------------------
4️⃣ Fully Optimized 1D DP (Best Method)

Use **one array**, loop weights backwards:

for (w = W → wt[i]):
      dp[w] = max(dp[w], val[i] + dp[w - wt[i]])

Backward loop ensures each item used only once.

-------------------------------------------------
🎯 Intuition:
At each item, decide:
- Take it?
- Or skip it?

DP stores the best value achievable for every capacity up to W.
-------------------------------------------------
*/
int f(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }

    if (dp[i][W] != -1)
        return dp[i][W];

    int not_take = f(i - 1, W, val, wt, dp);
    int take = INT_MIN;

    if (wt[i] <= W)
        take = val[i] + f(i - 1, W - wt[i], val, wt, dp);

    return dp[i][W] = max(take, not_take);
}

int knapsack_Memoization(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f(n - 1, W, val, wt, dp);
}

int knapsack_Tabulation(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base case
    for (int w = wt[0]; w <= W; w++)
        dp[0][w] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            int not_take = dp[i - 1][w];
            int take = INT_MIN;

            if (wt[i] <= w)
                take = val[i] + dp[i - 1][w - wt[i]];

            dp[i][w] = max(take, not_take);
        }
    }

    return dp[n - 1][W];
}

int knapsack_SpaceOptimization(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<int> prev(W + 1, 0);

    for (int w = wt[0]; w <= W; w++)
        prev[w] = val[0];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(W + 1, 0);
        for (int w = 0; w <= W; w++)
        {
            int not_take = prev[w];
            int take = INT_MIN;

            if (wt[i] <= w)
                take = val[i] + prev[w - wt[i]];

            curr[w] = max(take, not_take);
        }
        prev = curr;
    }

    return prev[W];
}

// Fully optimized 1D DP
int knapsack_1D(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<int> dp(W + 1, 0);

    for (int w = wt[0]; w <= W; w++)
        dp[w] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int w = W; w >= wt[i]; w--)
        {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }

    return dp[W];
}

int main()
{

    return 0;
}