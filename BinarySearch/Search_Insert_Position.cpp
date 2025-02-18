// URL: https://leetcode.com/problems/search-insert-position/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int main()
{
    vector<int> v = {1, 3, 5, 6};
    cout << searchInsert(v, 7);
    return 0;
}