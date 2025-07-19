// URL:-https://leetcode.com/problems/move-zeroes/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    // find first zero and and its index stored to j
    int j;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }
    // whenever u find a non zero swap element of arr[i] and arr[j]
    for (int i = j + 1; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}
int main()
{

    return 0;
}