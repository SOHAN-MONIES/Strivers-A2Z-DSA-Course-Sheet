// URL:
#include <bits/stdc++.h>
using namespace std;

int f(int idx, int target, vector<int> &coins, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return (target % coins[idx] == 0) ? target / coins[idx] : 1e9;
    }
    if (dp[idx][target] != -1)
    {
        return dp[idx][target];
    }
    int not_take = f(idx - 1, target, coins, dp);
    int take = 1e9;
    if (coins[idx] <= target)
    {
        take = 1 + f(idx, target - coins[idx], coins, dp);
    }
    return dp[idx][target] = min(not_take, take);
}

int minCoins_Memoization(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = f(n - 1, amount, coins, dp);
    if (ans == 1e9)
    {
        return -1;
    }
    return ans;
}

int minCoins_Tabulation(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int target = 0; target <= amount; target++)
    {
        dp[0][target] = (target % coins[0] == 0) ? target / coins[0] : 1e9;
    }
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int not_take = dp[i - 1][target];
            int take = 1e9;
            if (coins[i] <= target)
            {
                take = 1 + dp[i][target - coins[i]];
            }
            dp[i][target] = min(take, not_take);
        }
    }

    return dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount];
}

int minCoins(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1, 0);
    for (int target = 0; target <= amount; target++)
    {
        prev[target] = (target % coins[0] == 0) ? target / coins[0] : 1e9;
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(amount + 1, 0);
        for (int target = 0; target <= amount; target++)
        {
            int not_take = prev[target];
            int take = 1e9;
            if (coins[i] <= target)
            {
                take = 1 + curr[target - coins[i]];
            }
            curr[target] = min(take, not_take);
        }
        prev = curr;
    }

    return prev[amount] == 1e9 ? -1 : prev[amount];
}
int main()
{
    vector<int> arr = {25, 10, 5};
    cout << minCoins(arr, 30);
    return 0;
}