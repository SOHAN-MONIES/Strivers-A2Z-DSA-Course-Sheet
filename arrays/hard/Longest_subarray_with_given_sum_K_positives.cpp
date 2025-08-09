// URL: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
#include <bits/stdc++.h>
using namespace std;

/*
✅ Algorithm: Longest Subarray with Sum = k (Handles Positive, Negative, and Zero values)

Problem:
- Find the length of the longest contiguous subarray whose sum equals k.
- Works for arrays with both positive and negative numbers.

Steps:
1. Use a prefix sum approach with a hash map:
   - Key   = prefix sum value.
   - Value = earliest index where this prefix sum occurred.
2. Initialize:
   - sum = 0 (running prefix sum)
   - len = 0 (maximum subarray length found so far)
   - mpp[0] = -1 (base case: prefix sum 0 occurs before the array starts)
3. Traverse the array:
   - Add current element to sum.
   - If (sum - k) exists in map:
       - Update len = max(len, i - mpp[sum - k]).
   - If sum not already in map:
       - Store sum with its earliest index.
4. Return len.

⚠️ Assumptions:
- Array can contain any integers (positive, negative, or zero).

🕒 Time Complexity: O(n)
   - Single pass with O(1) average lookup time in hash map.

🧠 Space Complexity: O(n)
   - Stores prefix sums in hash map.
*/

int longestSubarray(vector<int> &arr, int k)
{
    int len = 0;
    unordered_map<int, int> mpp; // prefix sum -> earliest index
    int sum = 0;

    mpp[0] = -1; // base case: sum 0 exists at index -1  [imp this is base condition for  if from first index is equal to sum]

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        // If (sum - k) exists, we have a subarray with sum k
        if (mpp.find(sum - k) != mpp.end())
        {
            len = max(len, i - mpp[sum - k]);
        }

        // Store earliest occurrence of sum
        if (mpp.find(sum) == mpp.end()) // [if 2 0 0 0 3 is arr and k=3 without this condition wont work]
        {
            mpp[sum] = i;
        }
    }

    return len;
}

int longestSubarray(vector<int> &arr, int k)
{
    int len = 0;
    unordered_map<int, int> mpp; // prefix sum -> earliest index
    int sum = 0;

    mpp[0] = -1; // base case: sum 0 exists at index -1

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        // If (sum - k) exists, we have a subarray with sum k
        if (mpp.find(sum - k) != mpp.end())
        {
            len = max(len, i - mpp[sum - k]);
        }

        // Store earliest occurrence of sum
        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = i;
        }
    }

    return len;
}
/*
✅ Algorithm: Longest Subarray with Sum = k (Sliding Window for Non-negative Integers)

Problem:
- Find the length of the longest contiguous subarray whose sum equals k.
- Works efficiently when array elements are non-negative.

Steps:
1. Initialize two pointers: left = 0, right = 0.
2. Initialize sum = a[0], maxLen = 0.
3. Iterate while right < n:
   - While sum > k and left <= right:
       - Subtract a[left] from sum.
       - Increment left to shrink the window.
   - If sum == k, update maxLen with current window size (right - left + 1).
   - Move right pointer forward:
       - Add a[right] to sum if right < n.
4. Return maxLen.

⚠️ Assumption:
- Array contains non-negative integers. (Otherwise sliding window may not work correctly.)

🕒 Time Complexity: O(n)
   - Each element visited at most twice by left and right pointers.

🧠 Space Complexity: O(1)
   - Uses constant extra space.
*/

int getLongestSubarray(vector<int> &arr, long long target)
{
    int n = arr.size(); // size of the array.

    int left = 0, right = 0; // two pointers
    long long sum = arr[0];
    int maxLen = 0;

    while (right < n)
    {
        // Shrink window from left if sum > k
        while (left <= right && sum > target)
        {
            sum -= arr[left];
            left++;
        }

        // Check if sum equals k
        if (sum == target)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move right pointer forward
        right++;
        if (right < n)
            sum += arr[right];
    }

    return maxLen;
}

int subarraySum(vector<int> &nums, int k)
{

    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
                cnt++;
        }
    }

    return cnt;
}
int main() {
    vector<int> vec = {1, 2, 1, 2, 1};
    subarraySum(vec,3);
    return 0;
}