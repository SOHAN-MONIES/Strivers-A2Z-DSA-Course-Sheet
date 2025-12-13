// URL:https://leetcode.com/problems/delete-operation-for-two-strings/submissions/1851147973/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Minimum Deletions to Make Two Strings Equal
(Using Longest Common Subsequence)

Problem:
Given two strings word1 and word2, return the minimum number of deletions
required so that both strings become equal.

Key Insight:
To make both strings equal, we want to **keep only the Longest Common Subsequence (LCS)**.
Everything else must be deleted.

Formula:
    deletions = (len(word1) - LCS) + (len(word2) - LCS)
               = len(word1) + len(word2) - 2 * LCS

-------------------------------------------------
1️⃣ Compute LCS(word1, word2)

DP State:
    dp[i][j] = LCS of word1[0…i-1] and word2[0…j-1]

Transition:
If characters match:
      dp[i][j] = 1 + dp[i-1][j-1]
Else:
      dp[i][j] = max(dp[i-1][j], dp[i][j-1])

We use a space-optimized approach:
- `prev[j]` represents previous row
- `curr[j]` represents current row

Time Complexity: O(n × m)
Space Complexity: O(m)

-------------------------------------------------
2️⃣ Compute Minimum Deletions

Let:
    L = LCS(word1, word2)
    n = word1.length
    m = word2.length

Then:
    min deletions = (n - L) + (m - L)
                  = n + m - 2L

-------------------------------------------------
🎯 Intuition:
The LCS represents characters that already match and should be kept.
Everything not in LCS must be deleted from one string or the other.

Example:
word1 = "sea"
word2 = "eat"

LCS = "ea" (length 2)
Total deletions = 3 + 3 - 2*2 = 2

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
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
    }
    int minDistance(string word1, string word2)
    {
        int t_size = word1.size() + word2.size();
        return t_size - 2 * longestCommonSubsequence(word1, word2);
        ;
    }
};
int main()
{

    return 0;
}