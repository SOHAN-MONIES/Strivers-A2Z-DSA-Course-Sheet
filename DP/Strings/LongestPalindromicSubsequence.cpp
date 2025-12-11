// URL:https://leetcode.com/problems/longest-palindromic-subsequence/submissions/1851094105/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Longest Palindromic Subsequence (via LCS)

Problem:
Given a string `s`, find the length of the **longest subsequence** that is
also a **palindrome**.

Key Insight:
A palindrome reads the same forward and backward.
So:
    LPS(s) = LCS(s, reverse(s))

-------------------------------------------------
1️⃣ Longest Common Subsequence (Space Optimized DP)

DP Definition:
prev[j] = LCS value for previous row
curr[j] = LCS value for current row

Transition:
If characters match:
     curr[j] = 1 + prev[j-1]
Else:
     curr[j] = max(prev[j], curr[j-1])

Initialization:
prev[] = 0 for all j

Answer:
prev[m] after processing all rows

Time Complexity: O(n × m)
Space Complexity: O(m)

-------------------------------------------------
2️⃣ Longest Palindromic Subsequence

Steps:
1. Let s1 = original string
2. Let s2 = reverse(s1)
3. Compute LCS(s1, s2)
4. Return the LCS value

This gives the LPS (longest palindromic subsequence).

-------------------------------------------------
🎯 Intuition:
A subsequence becomes palindromic if it matches its reverse.
Thus LPS reduces perfectly to an LCS problem.

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
};

int main()
{

    return 0;
}