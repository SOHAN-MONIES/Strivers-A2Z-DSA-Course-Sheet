// URL:-https://leetcode.com/problems/move-zeroes/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// ✅ Algorithm to Move All Zeroes to End (In-Place, Order Preserved)

// 1. Find the first zero in the array, store its index in 'j'.
// 2. From index j+1 to end of array:
//    - If nums[i] != 0:
//      - Swap nums[i] and nums[j].
//      - Increment j (points to next zero position).

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
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZeroes(arr);
    return 0;
}