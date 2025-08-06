// URL: https://leetcode.com/problems/sort-colors/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void sortColorsb(vector<int> &nums)
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

/*
Algorithm: Sort Colors (Dutch National Flag Problem)

Assumptions during iteration:
- nums[0 ... low-1] → all 0s (sorted)
- nums[low ... mid-1] → all 1s (sorted)
- nums[mid ... high] → unknown (to be processed)
- nums[high+1 ... n-1] → all 2s (sorted)

Steps:
1. Initialize three pointers:
   - low = 0
   - mid = 0
   - high = n-1

2. While mid <= high:
   - If nums[mid] == 0:
       - Swap nums[low] and nums[mid]
       - Increment both low and mid
   - Else if nums[mid] == 1:
       - Increment mid
   - Else (nums[mid] == 2):
       - Swap nums[mid] and nums[high]
       - Decrement high (do not move mid yet, because swapped element needs checking)

3. Loop ends when mid > high → array is fully sorted.

Example:
   Input:  [2,0,2,1,1,0]
   Output: [0,0,1,1,2,2]

Time Complexity: O(n)
Space Complexity: O(1)
*/

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) // last element has to be checked
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> v3 = {2, 0, 1};
    sortColors(v3);
    for(auto num:v3){
        cout << num << endl;
    }
    return 0;
}