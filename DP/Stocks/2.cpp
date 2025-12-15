// URL:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Best Time to Buy and Sell Stock II (Unlimited Transactions)

Problem:
You are given an array `prices` where prices[i] is the stock price on day i.
You may complete as many transactions as you like (buy one and sell one share
multiple times), but you must sell before you buy again.

Goal:
Maximize total profit.

-------------------------------------------------
State Definition:

f(idx, buy):
- idx → current day
- buy → whether you are allowed to buy:
        buy = 1 → you can buy
        buy = 0 → you must sell or skip

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Base Case:
- If idx == n → no days left → profit = 0

Transitions:
If buy == 1:
- Option 1: Buy stock → -prices[idx] + f(idx+1, 0)
- Option 2: Skip day  → f(idx+1, 1)
Take max of both.

If buy == 0:
- Option 1: Sell stock → +prices[idx] + f(idx+1, 1)
- Option 2: Skip day   → f(idx+1, 0)
Take max of both.

Store result in dp[idx][buy].

Time Complexity: O(n × 2) → O(n)
Space Complexity: O(n × 2) + recursion stack

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up DP)

DP Table:
dp[idx][buy] = max profit from day idx with state `buy`

Initialization:
- dp[n][0] = dp[n][1] = 0

Fill table backwards from idx = n-1 to 0.

Final Answer:
dp[0][1]  → start from day 0 with permission to buy

Time Complexity: O(n)
Space Complexity: O(n × 2)

-------------------------------------------------
3️⃣ Space Optimized DP

Idea:
dp[idx] depends only on dp[idx+1], so we keep:
- next[2] → dp[idx+1]
- curr[2] → dp[idx]

Steps:
1. Initialize next[0] = next[1] = 0
2. Iterate idx from n-1 down to 0
3. Compute curr[buy] using next
4. Assign next = curr

Final Answer:
next[1]

Time Complexity: O(n)
Space Complexity: O(1)

-------------------------------------------------
🎯 Intuition:
At each day, decide:
- Buy, Sell, or Skip
DP ensures we explore all valid transaction sequences
without recomputation.

-------------------------------------------------
*/
int f(int idx, vector<int> &prices, int buy, vector<vector<int>> &dp)
{
    if (idx == prices.size())
    {
        return 0;
    }
    if (dp[idx][buy] != -1)
    {
        return dp[idx][buy];
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[idx] + f(idx + 1, prices, 0, dp), f(idx + 1, prices, 1, dp));
    }
    else
    {
        profit = max(prices[idx] + f(idx + 1, prices, 1, dp), f(idx + 1, prices, 0, dp));
    }
    return dp[idx][buy] = profit;
}
int maxProfit_Memoization(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, prices, 1, dp);
}
int maxProfit_Tabulation(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[idx] + dp[idx + 1][0], dp[idx + 1][1]);
            }
            else
            {
                profit = max(prices[idx] + dp[idx + 1][1], dp[idx + 1][0]);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> next(2, 0);
    next[0] = 0;
    next[1] = 0;
    for (int idx = n - 1; idx >= 0; idx--)
    {
        vector<int> curr(2, 0);
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[idx] + next[0], next[1]);
            }
            else
            {
                profit = max(prices[idx] + next[1], next[0]);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}
int main()
{

    return 0;
}