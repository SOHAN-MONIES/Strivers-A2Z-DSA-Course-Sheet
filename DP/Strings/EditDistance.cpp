// URL:https://leetcode.com/problems/edit-distance/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Edit Distance (Minimum Operations to Convert One String to Another)

Problem:
Given two strings word1 and word2, find the minimum number of operations
required to convert word1 into word2.

Allowed Operations:
1. Insert a character
2. Delete a character
3. Replace a character

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Function f(i, j):
- i → index in word1
- j → index in word2

Base Cases:
1. If i < 0 → need (j + 1) insertions to form word2[0..j]
2. If j < 0 → need (i + 1) deletions to remove word1[0..i]

If dp[i][j] already computed → return dp[i][j]

Transition:
- If word1[i] == word2[j]:
      No operation needed
      f(i, j) = f(i-1, j-1)
- Else:
      Consider all three operations:
      1. Delete  → f(i-1, j)
      2. Insert  → f(i, j-1)
      3. Replace → f(i-1, j-1)

      f(i, j) = 1 + min(delete, insert, replace)

Time Complexity: O(n × m)
Space Complexity: O(n × m) + recursion stack

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up DP)

DP Definition:
dp[i][j] = minimum operations to convert
           word1[0..i-1] → word2[0..j-1]

Initialization:
- dp[0][j] = j  (j insertions)
- dp[i][0] = i  (i deletions)

Transition:
If word1[i-1] == word2[j-1]:
    dp[i][j] = dp[i-1][j-1]
Else:
    dp[i][j] = 1 + min(
                    dp[i-1][j],    // delete
                    dp[i][j-1],    // insert
                    dp[i-1][j-1]   // replace
                )

Final Answer:
dp[n][m]

Time Complexity: O(n × m)
Space Complexity: O(n × m)

-------------------------------------------------
3️⃣ Space Optimized DP

Idea:
Each dp[i][j] depends only on:
- prev[j]     → dp[i-1][j]
- curr[j-1]   → dp[i][j-1]
- prev[j-1]   → dp[i-1][j-1]

Steps:
1. Initialize prev[j] = j
2. For each i:
      curr[0] = i
      For each j:
          if characters match:
              curr[j] = prev[j-1]
          else:
              curr[j] = 1 + min(prev[j], curr[j-1], prev[j-1])
3. prev = curr

Final Answer:
prev[m]

Time Complexity: O(n × m)
Space Complexity: O(m)

-------------------------------------------------
🎯 Intuition:
At every character, we try all valid operations and choose the minimum.
Dynamic Programming avoids recomputation of overlapping subproblems.
-------------------------------------------------
*/
int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (word1[i] == word2[j])
    {
        return f(i - 1, j - 1, word1, word2, dp);
    }
    return dp[i][j] = 1 + min(f(i - 1, j, word1, word2, dp), min(f(i, j - 1, word1, word2, dp), f(i - 1, j - 1, word1, word2, dp)));
}

int minDistance_Memoization(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, word1, word2, dp);
}

int minDistance_Tabulation(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[n][m];
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<int> prev(m + 1, 0);
    for (int j = 0; j <= m; j++)
    {
        prev[j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(m + 1, 0);
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
            }
        }
        prev = curr;
    }
    return prev[m];
}
int main()
{

    return 0;
}