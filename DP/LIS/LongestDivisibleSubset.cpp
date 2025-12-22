// URL:https://leetcode.com/problems/largest-divisible-subset/description/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Largest Divisible Subset (Ascending Order, DP + Reconstruction)

Problem:
Given a set of distinct positive integers `nums`,
find the **largest subset** such that for every pair (a, b) in the subset:
    a % b == 0 OR b % a == 0.

Return any one such subset.

-------------------------------------------------
Idea:

This problem is a **variation of LIS (Longest Increasing Subsequence)**.
Instead of checking increasing order, we check **divisibility**.

Sorting in ascending order ensures:
- When nums[i] > nums[prev], we only need to check:
      nums[i] % nums[prev] == 0

-------------------------------------------------
Preprocessing:

1. Sort the array in **ascending order**

-------------------------------------------------
State Definition:

dp[i]:
- Length of the largest divisible subset ending at index i

hash[i]:
- Stores the previous index in the subset ending at i
- Used for reconstruction

-------------------------------------------------
DP Computation:

Initialization:
- dp[i] = 1   (each number alone is a valid subset)
- hash[i] = i

Transition:
For each index i from 0 to n-1:
    For each previous index prev from 0 to i-1:
        If nums[i] % nums[prev] == 0 AND
           dp[prev] + 1 > dp[i]:
              dp[i] = dp[prev] + 1
              hash[i] = prev

-------------------------------------------------
Finding the Result:

1. Find index `idx` where dp[idx] is maximum
2. This index represents the **last element** of the largest divisible subset

-------------------------------------------------
Reconstruction:

- Start from idx
- Push nums[idx] into answer
- Move idx = hash[idx]
- Stop when hash[idx] == idx
- Reverse the answer to get ascending order

-------------------------------------------------
Final Answer:
The vector `ans` contains one largest divisible subset in ascending order.

-------------------------------------------------
Time Complexity:
O(n²)

-------------------------------------------------
Space Complexity:
O(n)

-------------------------------------------------
🎯 Intuition:
- Sorting ensures smaller numbers come first
- Divisibility flows naturally from smaller → larger
- This is identical to LIS, with `%` replacing `<`
- `hash` allows easy path reconstruction

-------------------------------------------------
*/

vector<int> largestSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<int> dp(n, 1), hash(n);
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if ((nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0) && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
    }

    int idx = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> ans;

    while (hash[idx] != idx)
    {
        ans.push_back(nums[idx]);
        idx = hash[idx];
    }
    ans.push_back(nums[idx]);
    return ans;
}
int main()
{

    return 0;
}