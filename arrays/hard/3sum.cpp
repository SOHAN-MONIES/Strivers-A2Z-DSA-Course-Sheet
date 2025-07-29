// URL:https://leetcode.com/problems/3sum/submissions/1715370732/
#include <bits/stdc++.h>
using namespace std;

/*
Algorithm: 3Sum Problem (Find all unique triplets that sum to 0)

1. Sort the array.
   - Sorting helps avoid duplicates and enables two-pointer technique.

2. Loop through the array with index i from 0 to n-1:
   - Skip duplicates for nums[i] (if nums[i] == nums[i-1]).

3. For each nums[i], set two pointers:
   - j = i + 1 (next element)
   - k = n - 1 (last element)

4. While j < k:
   - Compute sum = nums[i] + nums[j] + nums[k].
   - If sum == 0:
       - Store triplet {nums[i], nums[j], nums[k]}.
       - Move j forward while skipping duplicates.
       - Move k backward while skipping duplicates.
   - If sum > 0, decrement k (to reduce sum).
   - If sum < 0, increment j (to increase sum).

5. Continue until all triplets are checked.

Time Complexity: O(n^2)
    - Sorting takes O(n log n).
    - Outer loop runs n times, inner two-pointer runs O(n).
    - Overall O(n^2).

Space Complexity: O(1) (excluding result storage)
    - No extra data structures used apart from output.
*/

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue; // skip duplicates

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum == 0)
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                res.push_back(temp);

                while (j < k && nums[j] == nums[++j])
                {
                }
                while (j < k && nums[k] == nums[--k])
                {
                }
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    return res;
}

int main()
{

    return 0;
}