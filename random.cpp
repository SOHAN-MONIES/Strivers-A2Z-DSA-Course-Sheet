// URL: https://www.geeksforgeeks.org/problems/maximum-repeating-number4858/1?page=2&category=Hash&sortBy=difficulty
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int maxRepeating(int k, vector<int> &arr)
{
    unordered_map<int, int> mpp;
    for (auto num : arr)
    {
        mpp[num]++;
    }
    vector<pair<int, int>> p1;
    for (auto it : mpp)
    {
        p1.push_back({it.first, it.second});
    }
    sort(p1.begin(), p1.end(), cmp);
    return p1[0].first;
}

   

int main()
{
    vector<int> v1 = {2, 2, 1, 2};
    cout << maxRepeating(3, v1);

    return 0;
}