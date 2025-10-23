// URL:
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: House Robber II (Dynamic Programming + Space Optimization)

Problem:
- You are given an array `nums` where each element represents the amount of money in a house.
- The houses are arranged in a circle.
- You cannot rob two adjacent houses.
- Return the maximum amount you can rob.

Example:
Input: nums = [2,3,2]
Output: 3

-------------------------------------------------
✅ Intuition:
- This is a variation of the **House Robber I** problem, but the houses are in a circle.
- You cannot rob both the **first and last** houses together.
- So we break it into **two linear cases**:
  1️⃣ Rob houses from index 0 to n-2 (exclude last house)
  2️⃣ Rob houses from index 1 to n-1 (exclude first house)
- The answer is the maximum of these two cases.

-------------------------------------------------
1️⃣ Helper Function (Linear House Robber with Space Optimization):

Steps:
1. Initialize:
   - prev2 = 0 (dp[i-2])
   - prev1 = first house (based on which range we’re robbing)
2. Loop through houses in range:
   - pick = nums[i] + prev2
   - notPick = prev1
   - curr = max(pick, notPick)
   - Update prev2 = prev1, prev1 = curr
3. Return prev1 as max loot.

-------------------------------------------------
2️⃣ Main Function (Circular Case):

Steps:
1. If only 1 house → return nums[0].
2. Compute:
   - case1 = rob excluding last house → helper(nums, 1)
   - case2 = rob excluding first house → helper(nums, 0)
3. Return max(case1, case2).

-------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
-------------------------------------------------
*/
int helper(vector<int> &nums, int flag)
{

    int prev2 = 0;
    int prev1 = flag == 0 ? nums[1] : nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (flag == 0)
        {
            if (i == 1)
            {
                continue;
            }
        }

        if (flag == 1)
        {
            if (i == nums.size() - 1)
            {
                continue;
            }
        }
        int pick = nums[i] + prev2;
        int n_pick = prev1;
        int curr = max(pick, n_pick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int rob(vector<int> &nums)
{

    return max(helper(nums, 0), helper(nums, 1));
}
int main()
{
    vector<int> nums = {2, 3, 2};
    cout << rob(nums);
    return 0;
}