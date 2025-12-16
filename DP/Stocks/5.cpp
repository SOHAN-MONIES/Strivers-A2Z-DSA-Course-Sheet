// URL:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
#include <bits/stdc++.h>
using namespace std;
int f(int idx, vector<int> &prices, int buy, vector<vector<int>> &dp)
{
    if (idx >= prices.size())
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
        profit = max(prices[idx] + f(idx + 2, prices, 1, dp), f(idx + 1, prices, 0, dp));
    }
    return dp[idx][buy] = profit;
}
int maxProfit_Memoization(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, prices, 1, dp);
}
int maxProfit_TAB(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
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
                profit = max(prices[idx] + dp[idx + 2][1], dp[idx + 1][0]);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1];
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> next1(2, 0);
    vector<int> next2(2, 0);
    vector<int> curr(2, 0);
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[idx] + next1[0], next1[1]);
            }
            else
            {
                profit = max(prices[idx] + next2[1], next1[0]);
            }
            curr[buy] = profit;
        }
        next2 = next1;
        next1 = curr;
    }
    return next1[1];
}
int main()
{

    return 0;
}