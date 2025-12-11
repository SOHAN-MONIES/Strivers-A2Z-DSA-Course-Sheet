#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Longest Common Substring (DP)

Problem:
Given two strings s1 and s2, return the **length of the longest substring**
(common & continuous).

Difference from LCS:
- Subsequence → characters may skip positions.
- Substring  → characters must be *contiguous*.

Example:
s1 = "abcjkl"
s2 = "xycjkp"
Longest Common Substring = "cjk" → length = 3

-------------------------------------------------
1️⃣ Tabulation (Bottom-Up DP)

DP Definition:
dp[i][j] = length of longest common substring ending at:
           s1[i-1] and s2[j-1]

Transition:
- If characters match:
      dp[i][j] = 1 + dp[i-1][j-1]
- Else:
      dp[i][j] = 0   (because substring must be continuous)

Track `ans = max(dp[i][j])` during filling.

Base:
dp[..][0] = dp[0][..] = 0

Time Complexity: O(n × m)
Space Complexity: O(n × m)

-------------------------------------------------
2️⃣ Space Optimized DP

We only need:
- previous row → prev[]
- current row → cur[]

Transition remains:
cur[j] = (s1[i-1] == s2[j-1]) ? 1 + prev[j-1] : 0

Update ans each time.

Time Complexity: O(n × m)
Space Complexity: O(m)

-------------------------------------------------
🎯 Intuition:
Unlike LCS, mismatch resets the count to zero because substring must be continuous.
We record all matching streaks and track the maximum streak length.

-------------------------------------------------
*/

int longestCommonSubstr(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int longestCommonSubstr_Space(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                int val = 1 + prev[j - 1];
                cur[j] = val;
                ans = max(ans, val);
            }
            else
            {
                cur[j] = 0;
            }
        }
        prev = cur;
    }
    return ans;
}

int main()
{
    return 0;
}
