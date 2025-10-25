// URL:
#include <bits/stdc++.h>
using namespace std;

int helper(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = helper(i - 1, j, dp);
    int left = helper(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int uniquePaths_Recursion(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m - 1, n - 1, dp);
}
// TABULATION
int uniquePath_Tabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                int left = 0;
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int main()
{
    cout << uniquePath_Tabulation(3, 3);
    return 0;
}