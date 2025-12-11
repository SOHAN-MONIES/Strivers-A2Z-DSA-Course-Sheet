// URL:
#include <bits/stdc++.h>
using namespace std;

int generate(vector<int> &arr, int i, int target, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return 1;
    }
    if (i == 0)
    {
        return (arr[i] == target);
    }
    if (dp[i][target] != -1)
    {
        return dp[i][target];
    }
    int not_take = generate(arr, i - 1, target, dp);
    int take = 0;
    if (arr[i] <= target)
    {
        take = generate(arr, i - 1, target - arr[i], dp);
    }

    return dp[i][target] = take + not_take;
}

int perfectSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return generate(arr, n - 1, target, dp);
}
int main()
{
    vector<int> arr = {1, 2, 3};
    cout << perfectSum(arr, 3);
    return 0;
}