// URL:
#include <bits/stdc++.h>
using namespace std;

bool check(int i, int j, vector<string> &words)
{
    if (words[i].size() != words[j].size() + 1)
        return false;

    int p1 = 0, p2 = 0;
    bool skipped = false;

    while (p1 < words[i].size() && p2 < words[j].size())
    {
        if (words[i][p1] == words[j][p2])
        {
            p1++;
            p2++;
        }
        else
        {
            if (skipped)
                return false;
            skipped = true;
            p1++; // skip one char from larger string
        }
    }

    return true;
}

int longestStrChain(vector<string> &words)
{
    sort(words.begin(), words.end(),
         [](const string &a, const string &b)
         {
             return a.size() < b.size();
         });
    int n = words.size();
    vector<int> dp(n, 1);
    for (int idx = 0; idx < n; idx++)
    {
        for (int prev_idx = 0; prev_idx < idx; prev_idx++)
        {
            if (check(idx, prev_idx, words) && 1 + dp[prev_idx] > dp[idx])
            {
                dp[idx] = 1 + dp[prev_idx];
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int main()
{
    vector<string> words = {
        "a", "b", "ba", "bca", "bda", "bdca"};
    cout << longestStrChain(words);
    return 0;
}