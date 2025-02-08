// URL:-https://leetcode.com/problems/move-zeroes/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[i] != 0)
        {
            i++;
        }
        if (nums[i] == 0 && nums[j] != 0)
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }
}

int main()
{

    return 0;
}