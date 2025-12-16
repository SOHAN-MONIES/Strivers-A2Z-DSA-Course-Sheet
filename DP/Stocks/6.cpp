
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Best Time to Buy and Sell Stock with Transaction Fee

Problem:
You are given an array `prices` where prices[i] is the stock price on day i
and an integer `fee` representing the transaction fee.
You may complete as many transactions as you like, but:
- You must sell before you buy again
- Each sell operation incurs a transaction fee

Goal:
Maximize total profit.

-------------------------------------------------
State Definition:

f(idx, buy):
- idx → current day index
- buy → whether we are allowed to buy:
        buy = 1 → can buy
        buy = 0 → must sell or skip

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Base Case:
- If idx == n → no days left → profit = 0

Memoization:
- If dp[idx][buy] already computed → return it

Transitions:
If buy == 1:
- Option 1: Buy stock
      profit = -prices[idx] + f(idx+1, 0)
- Option 2: Skip day
      profit = f(idx+1, 1)

If buy == 0:
- Option 1: Sell stock (pay transaction fee)
      profit = prices[idx] - fee + f(idx+1, 1)
- Option 2: Skip day
      profit = f(idx+1, 0)

dp[idx][buy] = max(all options)

Time Complexity: O(n × 2) → O(n)
Space Complexity: O(n × 2) + recursion stack

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up DP)

DP Table:
dp[idx][buy] = max profit starting from day `idx`

Initialization:
- dp[n][0] = dp[n][1] = 0

Fill table backwards:
- idx from n-1 → 0
- buy from 0 → 1

Final Answer:
dp[0][1]  → start on day 0 with permission to buy

Time Complexity: O(n)
Space Complexity: O(n × 2)

-------------------------------------------------
3️⃣ Space Optimized DP

Idea:
dp[idx] depends only on dp[idx+1].

Use:
- next[2] → dp[idx+1]
- curr[2] → dp[idx]

Steps:
1. Initialize next[0] = next[1] = 0
2. Iterate idx from n-1 → 0
3. Compute curr using next
4. next = curr

Final Answer:
next[1]

Time Complexity: O(n)
Space Complexity: O(1)

-------------------------------------------------
🎯 Intuition:
The transaction fee is applied **only when selling**.
DP ensures that every buy–sell decision accounts for this fee
while still exploring all valid choices optimally.

-------------------------------------------------
*/

int f(int idx, vector<int> &prices, int buy, vector<vector<int>> &dp, int &fee)
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
        profit = max(prices[idx] - fee + f(idx + 1, prices, 1, dp), f(idx + 1, prices, 0, dp));
    }
    return dp[idx][buy] = profit;
}
int maxProfit_Memoization(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, prices, 1, dp, fee);
}
int maxProfit_Tabulation(vector<int> &prices, int fee)
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
                profit = max(prices[idx] - fee + dp[idx + 1][1], dp[idx + 1][0]);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];
}
int maxProfit(vector<int> &prices, int fee)
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
                profit = max(prices[idx] - fee + next[1], next[0]);
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