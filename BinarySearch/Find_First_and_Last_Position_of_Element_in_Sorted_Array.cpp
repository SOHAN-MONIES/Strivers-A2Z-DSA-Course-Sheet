// URL: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> v1;
    int n = nums.size();
    if (n == 0)
    {
        v1.push_back(-1);
        v1.push_back(-1);
    }
    auto lb = lower_bound(nums.begin(), nums.end(), target);
    auto ub = upper_bound(nums.begin(), nums.end(), target);
    if ((lb == nums.end() || *lb != target))
    {
        v1.push_back(-1);
        v1.push_back(-1);
    }
    else if (lb != nums.end() && *lb == target)
    {
        int fnum = distance(nums.begin(), lb);
        int lnum = distance(nums.begin(), ub) - 1;
        v1.push_back(fnum);
        v1.push_back(lnum);
    }
    return v1;
}

int main()
{
    // 1 3 6 8
    vector<int> v = {2, 2};
    vector<int> v2 = searchRange(v, 6);
    for (auto num : v2)
    {
        cout << num << " ";
    }
    return 0;
}