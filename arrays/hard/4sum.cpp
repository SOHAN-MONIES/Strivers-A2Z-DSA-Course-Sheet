// URL:https://leetcode.com/problems/4sum/description/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: 4Sum Problem (Two Pointers + Sorting)

Goal: Find all unique quadruplets [a, b, c, d] such that a + b + c + d == target.

1. Sort the input array.
2. Fix the first two numbers (i, j) using two nested loops:
   - Skip duplicates for both i and j.
3. Use two pointers (k = j+1, l = n-1) to find the remaining two numbers:
   - If the sum == target → store the quadruplet and move both pointers.
   - Skip duplicates while moving k and l.
   - If sum < target → increment k.
   - If sum > target → decrement l.

⚠️ Edge Case:
- Skip duplicates to avoid repeating the same quadruplet.

🕒 Time Complexity: O(n³)
   - Three nested loops + two pointers ⇒ n * n * n in the worst case.

🧠 Space Complexity: O(1) (excluding result storage)
   - No extra data structures used (other than the output vector).

📌 Example:
   Input: nums = [1, 0, -1, 0, -2, 2], target = 0
   Output: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
*/
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    // code here
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    res.push_back(temp);
                    k++;
                    l--;
                    while (k < l && nums[k - 1] == nums[k])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    k++;
                }
            }
        }
    }
    return res;
}
