// URL: https://leetcode.com/problems/subarray-sum-equals-k/submissions/1728683147/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Count Subarrays with Sum = k (Handles Positive, Negative, and Zero values)

Problem:
- Count the number of contiguous subarrays whose sum equals k.
- Works for arrays with both positive and negative numbers.

Steps:
1. Use a prefix sum approach with a hash map:
   - Key   = prefix sum value.
   - Value = count of times this prefix sum has occurred.
2. Initialize:
   - sum = 0 (running prefix sum)
   - cnt = 0 (number of valid subarrays found so far)
   - mpp[0] = 1 (base case: prefix sum 0 occurs once before array starts)
3. Traverse the array:
   - Add current element to sum.
   - Compute requiredSum = sum - k.
   - If requiredSum exists in map:
       - Add its count to cnt.
   - Increment frequency of current sum in map.
4. Return cnt.

⚠️ Assumptions:
- Array can contain any integers (positive, negative, or zero).

🕒 Time Complexity: O(n)
   - Single pass with O(1) average lookup time in hash map.

🧠 Space Complexity: O(n)
   - Stores prefix sums and their frequencies.
*/
int subarraySum(vector<int> &nums, int k)
{

    int cnt = 0;
    map<int, int> mpp;
    mpp[0] = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int r = sum - k;
        if (mpp.find(r) != mpp.end())
        {
            cnt += mpp[r];
        }
        mpp[sum]++;
    }

    return cnt;
}

int main() {
    
    return 0;
}