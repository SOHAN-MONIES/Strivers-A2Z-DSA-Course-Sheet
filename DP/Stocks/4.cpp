// URL:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Best Time to Buy and Sell Stock IV (At Most K Transactions)

Problem:
You are given an array `prices` where prices[i] is the stock price on day i.
You are allowed to complete **at most k transactions**.
Each transaction consists of one buy followed by one sell.
You must sell before buying again.

Goal:
Maximize the total profit.

-------------------------------------------------
State Definition:

dp[idx][buy][cap]:
- idx → current day index
- buy → whether we are allowed to buy:
        buy = 1 → can buy
        buy = 0 → must sell or skip
- cap → number of transactions remaining (1 … k)

-------------------------------------------------
State Transition:

If buy == 1:
- Option 1: Buy stock
      profit = -prices[idx] + dp[idx+1][0][cap]
- Option 2: Skip day
      profit = dp[idx+1][1][cap]

If buy == 0:
- Option 1: Sell stock (uses 1 transaction)
      profit = prices[idx] + dp[idx+1][1][cap-1]
- Option 2: Skip day
      profit = dp[idx+1][0][cap]

Take maximum of the options.

-------------------------------------------------
Base Cases:
1. idx == n → no days left → profit = 0
2. cap == 0 → no transactions left → profit = 0

-------------------------------------------------
Space Optimized Bottom-Up DP

Idea:
dp[idx] depends only on dp[idx+1], so we use:
- next[buy][cap] → dp[idx+1]
- curr[buy][cap] → dp[idx]

Steps:
1. Initialize next[][] = 0
2. Iterate idx from n-1 → 0
3. For each buy ∈ {0,1} and cap ∈ [1…k]:
      apply transitions using next[][]
4. After processing idx:
      next = curr

Final Answer:
next[1][k]  → start at day 0, allowed to buy, k transactions available

-------------------------------------------------
Time Complexity:
O(n × 2 × k) → O(nk)

Space Complexity:
O(2 × k) → O(k)

-------------------------------------------------
🎯 Intuition:
Every transaction = Buy + Sell.
We track remaining transactions using `cap` to prevent exceeding k.
DP explores all valid buy/sell/skip decisions optimally.

-------------------------------------------------
*/

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> next(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                int profit;
                if (buy)
                {
                    profit = max(-prices[idx] + next[0][cap], next[1][cap]);
                }
                else
                {
                    profit = max(+prices[idx] + next[1][cap - 1], next[0][cap]);
                }
                curr[buy][cap] = profit;
            }
        }
        next = curr;
    }
    return next[1][k];
}
int main()
{

    return 0;
}