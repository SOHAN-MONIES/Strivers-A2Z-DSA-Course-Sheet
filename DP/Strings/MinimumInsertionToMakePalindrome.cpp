// URL: https://leetcode.com/problems/longest-palindromic-subsequence/submissions/1851094105/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Minimum Insertions to Make a String Palindrome
(Using Longest Palindromic Subsequence)

Problem:
Given a string s, return the minimum number of insertions needed to make it a palindrome.

Key Insight:
The fewer characters already part of a *palindromic subsequence*, the fewer insertions we need.

Formula:
    min_insertions = n - LPS(s)

Where:
- LPS(s) = Longest Palindromic Subsequence length
- LPS(s) = LCS(s, reverse(s))

-------------------------------------------------
1️⃣ Compute LCS(s, reverse(s)) → gives LPS

LCS DP Transition:
If text1[i-1] == text2[j-1]:
    dp[i][j] = 1 + dp[i-1][j-1]
Else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

We use space-optimized DP with:
- prev[j] → previous row
- curr[j] → current row

Time Complexity: O(n²)
Space Complexity: O(n)

-------------------------------------------------
2️⃣ Compute Minimum Insertions
Since LPS already accounts for matching characters:

Minimum Insertions = length(s) - LPS

Example:
s = "mbadm"
LPS = "mam" → length = 3
Answer = 5 - 3 = 2

-------------------------------------------------
🎯 Intuition:
- We want the longest subsequence that is already a palindrome.
- Every character NOT in LPS must be inserted.
-------------------------------------------------
*/
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            vector<int> curr(m + 1, 0);
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }

    int longestPalindromeSubseq(string s)
    {
        string s1 = s;
        reverse(s.begin(), s.end());
        return longestCommonSubsequence(s, s1);
    }

    int minInsertions(string s)
    {
        return s.size() - longestPalindromeSubseq(s);
    }
};
