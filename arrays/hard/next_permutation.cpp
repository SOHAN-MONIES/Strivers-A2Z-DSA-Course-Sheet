// URL:  https://leetcode.com/problems/next-permutation/
#include <bits/stdc++.h>
using namespace std;

/*
Algorithm: Next Permutation (Lexicographically Next Greater Sequence)

1. Traverse the array from right to left to find the "breakpoint" index:
   - idx = largest index i such that nums[i] < nums[i+1].
   - If no such index exists (array is in descending order), reverse the whole array and return.

2. If idx is found:
   - Traverse again from the right to find the first element greater than nums[idx].
   - Swap nums[idx] with this element.

3. Reverse the subarray from idx+1 to end.
   - This ensures the suffix is the smallest possible (sorted ascending).

Example:
   nums = [1,2,3]
   Step 1: idx = 1 (nums[1]=2 < nums[2]=3)
   Step 2: Find element > 2 → nums[2]=3, swap → [1,3,2]
   Step 3: Reverse suffix after idx → [1,3,2]
   Final Answer = [1,3,2]

   nums = [3,2,1]
   No idx found → reverse → [1,2,3]

Time Complexity: O(n)
   - One pass to find idx, one pass to find swap, one pass to reverse suffix.

Space Complexity: O(1)
   - In-place swaps and reversals.
*/

void nextPermutation(vector<int> &nums)
{
    int idx = -1;
    int n = nums.size();

    // Step 1: Find the breakpoint
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            idx = i;
            break;
        }
    }

    // Step 2: If no breakpoint, reverse entire array
    if (idx == -1)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        // Step 3: Find the element just greater than nums[idx] and swap
        for (int i = n - 1; i > idx; i--)
        {
            if (nums[i] > nums[idx])
            {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        // Step 4: Reverse suffix
        reverse(nums.begin() + idx + 1, nums.end());
    }
}

int main() {
    
    return 0;
}