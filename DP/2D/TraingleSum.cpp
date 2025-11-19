// URL:
#include <bits/stdc++.h>
using namespace std;
int helper(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == triangle.size() - 1)
    {
        return triangle[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int down = triangle[i][j] + helper(i + 1, j, triangle, dp);
    int diag = triangle[i][j] + helper(i + 1, j + 1, triangle, dp);
    return dp[i][j] = min(down, diag);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(0, 0, triangle, dp);
}

int main()
{
    vector<vector<int>> grid = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    cout << minimumTotal(grid);
    return 0;
}