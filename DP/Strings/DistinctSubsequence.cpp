// URL:https://leetcode.com/problems/distinct-subsequences/description/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Distinct Subsequences (Dynamic Programming)

Problem:
Given two strings s and t, return the number of **distinct subsequences**
of s which equal t.

A subsequence:
- Keeps relative order
- May skip characters

Example:
s = "rabbbit"
t = "rabbit"
Output = 3

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Function f(i, j):
- i → index in string s
- j → index in string t

Base Cases:
1. If j < 0 → all characters of t matched → return 1
2. If i < 0 → s exhausted but t not matched → return 0

Transition:
- not_take = f(i-1, j)   // skip current character of s
- take = 0
- If s[i] == t[j]:
      take = f(i-1, j-1)

Answer:
    dp[i][j] = take + not_take

Time Complexity: O(n × m)
Space Complexity: O(n × m) + recursion stack

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up DP)

DP Definition:
dp[i][j] = number of ways to form t[0..j-1] using s[0..i-1]

Initialization:
- dp[i][0] = 1 for all i   (empty t can always be formed)
- dp[0][j] = 0 for j > 0   (non-empty t from empty s)

Transition:
If s[i-1] == t[j-1]:
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
Else:
    dp[i][j] = dp[i-1][j]

Final Answer:
dp[n][m]

Time Complexity: O(n × m)
Space Complexity: O(n × m)

-------------------------------------------------
3️⃣ Space Optimized DP

Idea:
Only previous row is needed to compute current row.

Steps:
1. Use two arrays:
   - prev[j] → previous row
   - curr[j] → current row
2. Initialize:
   prev[0] = 1
3. For each character in s:
   - curr[0] = 1
   - For each character in t:
        if s[i-1] == t[j-1]:
            curr[j] = prev[j-1] + prev[j]
        else:
            curr[j] = prev[j]
4. prev = curr

Final Answer:
prev[m]

Time Complexity: O(n × m)
Space Complexity: O(m)

-------------------------------------------------
🎯 Intuition:
At every character in s, we have two choices:
- Use it (if it matches current character of t)
- Skip it

The total count is the sum of both possibilities.
-------------------------------------------------
*/

int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (j < 0)
    {
        return 1;
    }
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int take = 0;
    int not_take = f(i - 1, j, s, t, dp);
    if (s[i] == t[j])
    {
        take = f(i - 1, j - 1, s, t, dp);
    }
    return dp[i][j] = take + not_take;
}
int numDistinct_Memoization(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, s, t, dp);
}
int numDistinct_Tabulation(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            long take = 0;
            long not_take = dp[i - 1][j];
            if (s[i - 1] == t[j - 1])
            {
                take = dp[i - 1][j - 1];
            }
            dp[i][j] = take + not_take;
        }
    }
    return dp[n][m];
}
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<int> prev(m + 1, 0);
    prev[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(m + 1, 0);
        curr[0] = 1;
        for (int j = 1; j <= m; j++)
        {
            long take = 0;
            long not_take = prev[j];
            if (s[i - 1] == t[j - 1])
            {
                take = prev[j - 1];
            }
            curr[j] = take + not_take;
        }
        prev = curr;
    }
    return prev[m];
}
int main()
{
    string s1, s2;
    s1 = "babgbag";
    s2 = "bag";
    cout << numDistinct(s1, s2);
    return 0;
}