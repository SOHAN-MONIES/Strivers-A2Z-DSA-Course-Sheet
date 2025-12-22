// URL:
#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &nums)

{
    int n = nums.size();
    vector<int> dp(n, 1), cnt(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] > nums[prev])
            {
                if (dp[prev] + 1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev];
                }
                else if (dp[prev] + 1 == dp[i])
                {
                    cnt[i] += cnt[prev];
                }
            }
        }
    }
    int len = *max_element(dp.begin(), dp.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == len)
        {
            ans += cnt[i];
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 4, 3, 5, 4, 7, 2};
    cout << findNumberOfLIS(arr);
    return 0;
}