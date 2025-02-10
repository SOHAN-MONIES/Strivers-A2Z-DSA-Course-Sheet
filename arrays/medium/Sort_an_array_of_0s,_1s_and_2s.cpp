// URL: https://leetcode.com/problems/sort-colors/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void sortColors(vector<int> &nums)
{
    int x = 0;
    int y = 0;
    int z = 0;
    for (auto num : nums)
    {
        if (num == 0)
            x++;
        else if (num == 1)
            y++;
        else
            z++;
    }
    for (int i = 0; i < x; i++)
    {
        nums[i] = 0;
    }
    for (int i = x; i < x + y; i++)
    {
        nums[i] = 1;
    }
    for (int i = x + y; i < nums.size(); i++)
    {
        nums[i] = 2;
    }
    for (auto it : nums)
    {
        cout << it << " ";
    }
}

int main()
{
    vector<int> v3 = {2, 0, 1};
    sortColors(v3);
    return 0;
}