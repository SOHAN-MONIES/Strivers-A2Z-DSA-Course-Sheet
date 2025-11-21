// URL: https://leetcode.com/problems/unique-paths-ii/
#include <bits/stdc++.h>
using namespace std;

/*
----------------------------------------------------------
RECURSION + MEMOIZATION
----------------------------------------------------------
Same idea as Unique Paths I, but:
If grid[i][j] == 1 → obstacle → 0 ways.

Transition:
    ways[i][j] = ways[i-1][j] (up) + ways[i][j-1] (left)

Base cases:
1. If obstacle at (0,0) → return 0
2. If (i == 0 && j == 0) → return 1   (starting point)
3. If out of bounds → 0
----------------------------------------------------------
*/

int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && grid[i][j] == 1)
        return 0;

    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = helper(i - 1, j, grid, dp);
    int left = helper(i, j - 1, grid, dp);

    return dp[i][j] = up + left;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n - 1, m - 1, obstacleGrid, dp);
}

/*
----------------------------------------------------------
TABULATION (BOTTOM-UP DP)
----------------------------------------------------------
dp[i][j] = number of ways to reach cell (i,j)

Rules:
- If obstacle → dp[i][j] = 0
- Starting cell (0,0) = 1 (if no obstacle)
- Otherwise:
      dp[i][j] = dp[i-1][j] + dp[i][j-1]
----------------------------------------------------------
*/

int uniquePathsWithObstacles_Tabulation(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    if (obstacleGrid[0][0] == 1)
        return 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;

                dp[i][j] = up + left;
            }
        }
    }

    return dp[m - 1][n - 1];
}

/*
----------------------------------------------------------
SPACE OPTIMIZED DP (1D ARRAY)
----------------------------------------------------------
We keep only a single 1D dp array representing the current row.

dp[j] = ways to reach column j in the current row.

Update rule:
- If obstacle: dp[j] = 0
- Otherwise:
      dp[j] = dp[j]      (from up)
             + dp[j-1]   (from left)
----------------------------------------------------------
*/

int uniquePathsWithObstacles_SpaceOptimized(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> dp(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[j] = 0; // obstacle blocks everything
            }
            else if (i == 0 && j == 0)
            {
                dp[j] = 1; // start point
            }
            else
            {
                if (j > 0)
                    dp[j] += dp[j - 1]; // up(dp[j]) + left(dp[j-1])
            }
        }
    }

    return dp[n - 1];
}

int main()
{
    return 0;
}
