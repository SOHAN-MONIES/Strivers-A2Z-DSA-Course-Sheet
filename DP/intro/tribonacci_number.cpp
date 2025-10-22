// URL:
#include <bits/stdc++.h>
using namespace std;

int helper(int n, vector<int> &dp)
{
    if (n == 0)
        return dp[0] = 0;
    if (n == 1 || n == 2)
        return dp[n] = 1; // covers both 1 and 2

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = helper(n - 1, dp) + helper(n - 2, dp) + helper(n - 3, dp);
}
int tribonacci(int n)
{
    vector<int> dp(n + 1, -1);

    return helper(n, dp);
}
int main()
{
    cout << tribonacci(4);
    return 0;
}