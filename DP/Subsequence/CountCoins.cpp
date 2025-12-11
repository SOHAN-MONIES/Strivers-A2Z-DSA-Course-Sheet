// URL:https://leetcode.com/problems/coin-change-ii/
#include <bits/stdc++.h>
using namespace std;
int f(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return (amount % coins[idx] == 0) ? 1 : 0;
    }
    if (amount == 0)
    {
        return 1;
    }
    if (dp[idx][amount] != -1)
    {
        return dp[idx][amount];
    }
    int not_take = 0 + f(idx - 1, amount, coins, dp);
    int take = 0;
    if (coins[idx] <= amount)
    {
        take = f(idx, amount - coins[idx], coins, dp);
    }
    return dp[idx][amount] = take + not_take;
}

int change_Memoization(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return f(n - 1, amount, coins, dp);
}

int change_Tabulation(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int target = 0; target <= amount; target++)
    {
        dp[0][target] = (target % coins[0] == 0) ? 1 : 0;
    }
    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 0; target <= amount; target++)
        {
            long not_take = 0 + dp[idx - 1][target];
            long take = 0;
            if (coins[idx] <= target)
            {
                take = dp[idx][target - coins[idx]];
            }
            dp[idx][target] = take + not_take;
        }
    }

    return dp[n - 1][amount];
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int target = 0; target <= amount; target++)
    {
        dp[0][target] = (target % coins[0] == 0);
    }
    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 0; target <= amount; target++)
        {
            long not_take = dp[idx - 1][target];
            long take = 0;
            if (coins[idx] <= target)
                take = dp[idx][target - coins[idx]];
            dp[idx][target] = take + not_take;
        }
    }
    return dp[n - 1][amount];
}

int main()
{

    return 0;
}