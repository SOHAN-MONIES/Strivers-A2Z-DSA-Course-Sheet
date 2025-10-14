// URL: https://leetcode.com/problems/max-consecutive-ones-iii/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Max Consecutive Ones III
(Using Sliding Window)

🧩 Problem:
Given a binary array `nums` and an integer `k`,
you can flip at most `k` zeros to ones.
Find the length of the longest subarray that contains only 1s after flipping.

-------------------------------------------------
⚙️ Steps:

1. Initialize:
   - `l = 0`, `r = 0` → window boundaries.
   - `zeros = 0` → counts the number of 0s in the current window.
   - `maxOnes = 0` → stores the maximum window size found so far.

2. Iterate while `r < nums.size()`:
   - If `nums[r] == 0`, increment `zeros` (since we encountered a zero).

3. If the number of zeros exceeds `k` (i.e., we flipped too many):
   - Shrink the window from the left (`l++`)
   - If the left element was 0, decrement `zeros`
   - Continue shrinking until `zeros <= k`

4. Update the maximum window length:
   - `maxOnes = max(maxOnes, r - l + 1)`

5. Move the right pointer forward (`r++`) to expand the window.

6. After the loop ends, return `maxOnes`.

-------------------------------------------------
🧠 Intuition:
We maintain a **sliding window** that always contains at most `k` zeros.
Whenever the window becomes invalid (more than `k` zeros),
we move the left pointer `l` to make it valid again.
This ensures we check all possible valid windows in O(n) time.

-------------------------------------------------
📊 Time Complexity: O(n)
   - Each element is visited at most twice (once by `r`, once by `l`).

💾 Space Complexity: O(1)
   - Only a few integer variables are used.

-------------------------------------------------
🔢 Example:
Input:
nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2

Window progress:
r=0..2 → [1,1,1] → zeros=0 → max=3
r=3 → [1,1,1,0] → zeros=1 → max=
*/
int longestOnes(vector<int> &nums, int k)
{
    int maxOnes = 0;
    int l = 0;
    int r = 0;
    int zeros = 0;
    while (r < nums.size())
    {
        if (nums[r] == 0)
        {
            zeros++;
        }
        while (zeros > k)
        {
            if (nums[l] == 0)
            {
                zeros--;
            }
            l++;
        }
        if (zeros <= k)
            maxOnes = max(maxOnes, r - l + 1);
        r++;
    }
    return maxOnes;
}

int main()
{
    vector<int> ones = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << longestOnes(ones, 3);
    return 0;
}