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

int findClosest(vector<int> &arr, int k)
{
    int n = arr.size();
    if (arr.size() == 1)
    {
        return arr[0];
    }
    int index = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    if (index == 0)
    {
        return arr[0];
    }
    if (index == arr.size() - 1)
    {
        return arr[-2];
    }
    int d1 = abs(k - arr[index - 1]);
    int d2 = abs(k - arr[index ]);
    if (d1 < d2)
    {
        return arr[index - 1];
    }
    else if (d2 < d1)
    {
        return arr[index ];
    }
    else
    {
        return arr[index ] > arr[index - 1] ? arr[index ] : arr[index - 1];
    }
}

int main()
{
    vector<int> v1 = {2,3,5,8,20};
    cout << findClosest(v1, 2);

    return 0;
}