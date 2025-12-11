// URL:
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Longest Common Subsequence (LCS)

Problem:
Given two strings s1 and s2, return the length of their **Longest Common Subsequence**.
A subsequence:
- does NOT require contiguous characters
- order must be preserved.

Example:
s1 = "abcde"
s2 = "ace"
LCS = "ace" → length = 3

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Function f(i, j):
- Base case:
    - If i < 0 OR j < 0 → return 0
- If dp[i][j] already computed → return it
- If characters match:
        1 + f(i-1, j-1)
- Else:
        max( f(i-1, j), f(i, j-1) )

Time Complexity: O(n × m)
Space Complexity: O(n × m) + recursion stack

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up DP)

Steps:
1. Create dp[n+1][m+1] initialized with 0
2. Loop over all indices:
       If str1[i-1] == str2[j-1]:
            dp[i][j] = 1 + dp[i-1][j-1]
       Else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
3. Answer = dp[n][m]

Time Complexity: O(n × m)
Space Complexity: O(n × m)

-------------------------------------------------
3️⃣ Space Optimized DP (1D Rolling Arrays)

Idea:
- Only **previous row** and **current row** are needed.

Transition:
cur[j] =
    if match → 1 + prev[j-1]
    else     → max(prev[j], cur[j-1])

After each row: prev = cur

Time Complexity: O(n × m)
Space Complexity: O(m)

-------------------------------------------------
🎯 Intuition:
- LCS checks two possibilities at each pair (i, j):
      → take both characters (only if equal)
      → skip either character
- DP stores best answer up to each prefix.

-------------------------------------------------
*/
int func(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + func(s1, s2, ind1 - 1, ind2 - 1, dp);
    else
        return dp[ind1][ind2] = max(func(s1, s2, ind1, ind2 - 1, dp), func(s1, s2, ind1 - 1, ind2, dp));
}

int lcs(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (str1[ind1 - 1] == str2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }
    return dp[n][m];
}

int lcs(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (str1[ind1 - 1] == str2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
        }
        prev = cur;
    }
    return prev[m];
}

int main()
{
    return 0;
}
