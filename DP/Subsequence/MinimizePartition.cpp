// URL:https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/
#include <bits/stdc++.h>
using namespace std;
int minimumDifference(vector<int> &arr)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= sum)
    {
        dp[0][arr[0]] = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= sum; target++)
        {
            bool not_take = dp[i - 1][target];
            bool take = false;
            if (arr[i] <= target)
            {
                take = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = take || not_take;
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[n - 1][i])
        {
            int s1 = i;
            int s2 = sum - i;
            int abs_ans = abs(s2 - s1);
            ans = min(ans, abs_ans);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {2, -1, 0, 4, -2, -9};
    cout << minimumDifference(arr);
    return 0;
}