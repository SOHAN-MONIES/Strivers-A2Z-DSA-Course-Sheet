// URL:https://leetcode.com/problems/largest-divisible-subset/description/
#include <bits/stdc++.h>
using namespace std;
vector<int> largestSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), greater<int>());

    int n = nums.size();
    vector<int> dp(n, 1), hash(n);
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if ((nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0) && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
    }

    int idx = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> ans;

    while (hash[idx] != idx)
    {
        ans.push_back(nums[idx]);
        idx = hash[idx];
    }
    ans.push_back(nums[idx]);
    return ans;
}
int main()
{

    return 0;
}