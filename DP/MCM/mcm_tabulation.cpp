// URL:https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
#include <bits/stdc++.h>
using namespace std;
int matrixMultiplication(vector<int> &arr)
{

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}
int main()
{

    return 0;
}