// URL:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iiis/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Best Time to Buy and Sell Stock III (At Most 2 Transactions)

Problem:
You are given an array `prices` where prices[i] is the stock price on day i.
You are allowed to complete **at most 2 transactions**.
Each transaction consists of one buy followed by one sell.
You must sell before buying again.

Goal:
Maximize the total profit.

-------------------------------------------------
State Definition:

f(idx, buy, cap):
- idx → current day index
- buy → whether we are allowed to buy:
        buy = 1 → can buy
        buy = 0 → must sell or skip
- cap → number of transactions remaining (max = 2)

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Base Cases:
1. If idx == n → no days left → profit = 0
2. If cap == 0 → no transactions left → profit = 0

Memoization:
If dp[idx][buy][cap] already computed → return it.

Transitions:
If buy == 1:
- Option 1: Buy stock
      profit = -prices[idx] + f(idx+1, 0, cap)
- Option 2: Skip day
      profit = f(idx+1, 1, cap)

If buy == 0:
- Option 1: Sell stock (uses 1 transaction)
      profit = prices[idx] + f(idx+1, 1, cap-1)
- Option 2: Skip day
      profit = f(idx+1, 0, cap)

dp[idx][buy][cap] = max(all options)

Time Complexity: O(n × 2 × 3) → O(n)
Space Complexity: O(n × 2 × 3) + recursion stack

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up DP)

DP Table:
dp[idx][buy][cap] = max profit starting from day `idx`

Initialization:
- dp[n][*][*] = 0  (no days left)
- dp[*][*][0] = 0  (no transactions left)

Fill table backwards:
- idx from n-1 → 0
- buy from 0 → 1
- cap from 1 → 2

Final Answer:
dp[0][1][2]  → start from day 0, allowed to buy, 2 transactions left

Time Complexity: O(n)
Space Complexity: O(n × 2 × 3)

-------------------------------------------------
3️⃣ Space Optimized DP

Idea:
dp[idx] depends only on dp[idx+1].

Use:
- next[buy][cap] → dp[idx+1]
- curr[buy][cap] → dp[idx]

Steps:
1. Initialize next[][] = 0
2. Iterate idx from n-1 → 0
3. Compute curr using next
4. Assign next = curr after each idx

Final Answer:
next[1][2]

Time Complexity: O(n)
Space Complexity: O(2 × 3) → O(1)

-------------------------------------------------
🎯 Intuition:
Every transaction = Buy + Sell.
We track remaining transactions (cap) to prevent exceeding 2.
DP ensures optimal decisions at every day without recomputation.

-------------------------------------------------
*/

int f(int idx, int buy, int cap,
      vector<int> &prices,
      vector<vector<vector<int>>> &dp)
{

    if (idx == prices.size() || cap == 0)
        return 0;

    if (dp[idx][buy][cap] != -1)
        return dp[idx][buy][cap];

    int profit;
    if (buy)
    {
        profit = max(
            -prices[idx] + f(idx + 1, 0, cap, prices, dp),
            f(idx + 1, 1, cap, prices, dp));
    }
    else
    {
        profit = max(
            prices[idx] + f(idx + 1, 1, cap - 1, prices, dp),
            f(idx + 1, 0, cap, prices, dp));
    }

    return dp[idx][buy][cap] = profit;
}

int maxProfit_Memo(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, 1, 2, prices, dp);
}
int maxProfit_Tabulation(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {

                if (buy)
                {
                    dp[idx][buy][cap] = max(
                        -prices[idx] + dp[idx + 1][0][cap],
                        dp[idx + 1][1][cap]);
                }
                else
                {
                    dp[idx][buy][cap] = max(
                        prices[idx] + dp[idx + 1][1][cap - 1],
                        dp[idx + 1][0][cap]);
                }
            }
        }
    }

    return dp[0][1][2];
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> next(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {

                if (buy)
                {
                    curr[buy][cap] = max(
                        -prices[idx] + next[0][cap],
                        next[1][cap]);
                }
                else
                {
                    curr[buy][cap] = max(
                        prices[idx] + next[1][cap - 1],
                        next[0][cap]);
                }
            }
        }
        next = curr; // ✅ after full idx
    }

    return next[1][2];
}

int main()
{
    vector<int> stocks = {1, 2, 3, 4, 5};
    cout << maxProfit(stocks);
    return 0;
}