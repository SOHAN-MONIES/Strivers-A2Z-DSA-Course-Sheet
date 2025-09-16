// URL: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=problem-list-v2&envId=string-matching
#include <bits/stdc++.h>
using namespace std;
vector<int> strStr(string text, string pattern)
{
    vector<int> res;
    int j = 0;
    int org = 0;
    for (int i = 0; i < text.size(); i++)
    {

        if (text[i] == pattern[j])
        {
            if (j == 0)
            {
                org = i;
            }
            j++;
        }
        else if (text[i] != pattern[j])
        {
            if (j > 0)
            {
                i = org;
            }
            j = 0;
        }
        if (j == pattern.size())
        {
            int ans = i - pattern.size() + 1;
            res.push_back(ans);
        }
    }

    return res;
}

int main()
{
    vector<int> res = strStr("geeksforgeeks", "geek");
    for (auto ele : res)
    {
        cout << ele << " ";
    }
    return 0;
}