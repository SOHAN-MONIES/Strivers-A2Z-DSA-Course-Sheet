// URL: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=problem-list-v2&envId=string-matching
#include <bits/stdc++.h>
using namespace std;
// int strStr(string txt, string pat)
// {
//     int res = -1;
//     int j = 0;
//     int org = 0;
//     for (int i = 0; i < txt.size(); i++)
//     {

//         if (txt[i] == pat[j])
//         {
//             if (j == 0)
//             {
//                 org = i;
//             }
//             j++;
//         }
//         else if (txt[i] != pat[j])
//         {
//             if (j > 0)
//             {
//                 i = org;
//             }
//             j = 0;
//         }
//         if (j == pat.size())
//         {
//             return i - pat.size() + 1;
//         }
//     }

//     return res;
// }

int strStr(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();

    for (int i = 0; i <= n - m; i++)
    { // starting index in txt
        int j = 0;
        for (; j < m; j++)
        { // check every char in pat
            if (txt[i+j] != pat[j])
            {
                break; // mismatch -> break inner loop
            }
        }
        if (j == m)
        {
            return i; // full match found
        }
    }
    return -1; // not found
}
int main()
{
    cout << strStr("sadsadh", "sadh");
    return 0;
}