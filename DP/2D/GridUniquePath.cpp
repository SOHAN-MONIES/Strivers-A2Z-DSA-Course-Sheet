// URL: https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
RECURSION + MEMOIZATION ALGORITHM
---------------------------------------------------------
The robot is at (i, j). To reach (i, j), it must come from:
    - (i-1, j)  (up)
    - (i, j-1)  (left)
So,
    dp[i][j] = dp[i-1][j] + dp[i][j-1]

Base Cases:
1. (0,0) → 1 way (starting point)
2. Out of bounds → 0 ways
---------------------------------------------------------
*/

int helper(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = helper(i - 1, j, dp);
    int left = helper(i, j - 1, dp);

    return dp[i][j] = up + left;
}

int uniquePaths_Recursion(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m - 1, n - 1, dp); // FIXED: dp must be passed
}

/*
---------------------------------------------------------
TABULATION ALGORITHM (BOTTOM UP DP)
---------------------------------------------------------
We build a table dp[m][n].

dp[0][0] = 1

For each cell:
    dp[i][j] = dp[i-1][j] (from top) + dp[i][j-1] (from left)
If i == 0 → no up
If j == 0 → no left
---------------------------------------------------------
*/

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
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

/*
---------------------------------------------------------
SPACE OPTIMIZED DP
---------------------------------------------------------
Instead of full matrix, keep only:
    prev[j] → previous row
    curr[j] → current row

Transition:
    curr[j] = prev[j] + curr[j-1]

---------------------------------------------------------
*/

int uniquePathsSpaceOptimized(int m, int n)
{
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);

        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? curr[j - 1] : 0;
                curr[j] = up + left;
            }
        }

        prev = curr;
    }

    return prev[n - 1];
}

int main()
{
    cout << uniquePath_Tabulation(3, 2);
    return 0;
}
