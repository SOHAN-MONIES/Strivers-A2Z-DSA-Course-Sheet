// URL:
#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<int> &cuts, vector<vector<long>> &dp)
{
    // Base case: no cut possible
    if (j == i + 1)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    long ans = 1e9;

    for (int k = i + 1; k < j; k++)
    {
        long cost = (cuts[j] - cuts[i]) + f(i, k, cuts, dp) + f(k, j, cuts, dp);
        ans = min(ans, cost);
    }

    return dp[i][j] = ans;
}

int minCost(int n, vector<int> &cuts)
{
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    int m = cuts.size();
    vector<vector<long>> dp(m, vector<long>(m, -1));

    return f(0, m - 1, cuts, dp);
}

int minCost(int n, vector<int> &cuts)
{
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    int m = cuts.size();
    vector<vector<long>> dp(m, vector<long>(m, 0));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < m; j++)
        {

            // base case: no cut possible
            if (j == i + 1)
            {
                dp[i][j] = 0;
                continue;
            }

            long ans = 1e9;

            for (int k = i + 1; k < j; k++)
            {
                long cost = (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j];
                ans = min(ans, cost);
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][m - 1];
}

int main()
{

    return 0;
}