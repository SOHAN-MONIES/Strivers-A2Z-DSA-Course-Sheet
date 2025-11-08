// URL:https://leetcode.com/problems/minimum-path-sum/
#include <bits/stdc++.h>
using namespace std;
int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[i][j];

    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + helper(i - 1, j, grid, dp);
    int left = grid[i][j] + helper(i, j - 1, grid, dp);

    return dp[i][j] = min(up, left);
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m - 1, n - 1, grid, dp);
}
int minPathSum_TABULATION(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];

            else
            {
                int up = (i > 0) ? dp[i - 1][j] : 1e9;
                int left = (j > 0) ? dp[i][j - 1] : 1e9;
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }

    return dp[m - 1][n - 1];
}
int minPathSum_SPACE_OPTIMIZED(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];
            else
            {
                int up = (i > 0) ? prev[j] : 1e9;
                int left = (j > 0) ? curr[j - 1] : 1e9;
                curr[j] = grid[i][j] + min(up, left);
            }
        }
        prev = curr;
    }

    return prev[n - 1];
}

int main()
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    cout << minPathSum(grid) << endl;
    cout << minPathSum_TABULATION(grid);
    return 0;
}