// URL: https://leetcode.com/problems/majority-element/description/
#include <bits/stdc++.h>
using namespace std;

/*
✅ Algorithm: Boyer-Moore Voting Algorithm – Majority Element

Problem:
- Find the element that appears more than ⌊n/2⌋ times in an array.
- Such an element is guaranteed to exist.

Steps:
1. Initialize:
   - candidate (no initial value needed)
   - count = 0
2. Traverse through each element in nums:
   a) If count == 0:
         - Set candidate to current element
         - Set count = 1
   b) Else if current element == candidate:
         - Increment count
   c) Else:
         - Decrement count
3. After one full pass, candidate holds the majority element.
4. Return candidate.

⚠️ Assumption:
- The array always contains a majority element (appears > n/2 times).

🕒 Time Complexity: O(n)
   - Only one pass over the array.

🧠 Space Complexity: O(1)
   - Only two variables used.
*/

int majorityElement(vector<int> &nums)
{
    int candidate;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
            count = 1;
        }
        else if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

int main() {
    
    return 0;
}