// URL: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        int m = (h + l) / 2;
        if (nums[m] == target)
            return true;
        if (nums[l] == nums[m] && nums[h] == nums[m])
        {
            l++;
            h--;
        }
        if (nums[l] <= nums[m])
        {
            if (target >= nums[l] && target <= nums[m])
                h = m - 1;
            else
                l = m + 1;
        }
        else
        {
            if (target >= nums[m] && target <= nums[h])
                l = m + 1;
            else
                h = m - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> v1 = {2, 5, 6, 0, 0, 1, 2};
    search(v1, 0);
    return 0;
}