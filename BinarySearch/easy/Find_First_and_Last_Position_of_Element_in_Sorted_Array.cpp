// URL: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> v1;
    auto itl = lower_bound(nums.begin(), nums.end(), target);
    auto itu = upper_bound(nums.begin(), nums.end(), target);
    if (itl == nums.end() || *itl != target)
    {
        v1.push_back(-1);
        v1.push_back(-1);
        return v1;
    }
    int d1 = distance(nums.begin(), itl);
    int d2 = distance(nums.begin(), itu) - 1;
    v1.push_back(d1);
    v1.push_back(d2);
    return v1;
}

int main()
{

    vector<int> v = {2, 2, 6, 6};
    vector<int> v2 = searchRange(v, 6);
    for (auto num : v2)
    {
        cout << num << " ";
    }
    return 0;
}