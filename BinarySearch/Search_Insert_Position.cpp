// URL: https://leetcode.com/problems/search-insert-position/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    auto lb = lower_bound(nums.begin(), nums.end(), target);
    if (lb != nums.end() && target == *lb)
    {
        return distance(nums.begin(), lb);
    }
    else if (lb != nums.end() && target != *lb)
        return distance(nums.begin(), lb);
    else
        return n;
}

int main()
{
    vector<int> v = {1, 3, 5, 6};
    cout << searchInsert(v, 7);
    return 0;
}