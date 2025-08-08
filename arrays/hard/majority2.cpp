// URL: https://leetcode.com/problems/majority-element/description/
#include <bits/stdc++.h>
using namespace std;

/*
✅ Algorithm: Boyer-Moore Voting Algorithm – Majority Element

Problem:
- Find the element that appears more than ⌊n/2⌋ times in the array.
- Such an element is guaranteed to exist.

Steps:
1. Initialize:
   - candidate = nums[0]
   - count = 1
2. Traverse the array:
   - If count == 0 → set current element as new candidate and count = 1.
   - Else if current element == candidate → increment count.
   - Else → decrement count.
3. The final candidate is the majority element (guaranteed by the problem).

⚠️ Assumption:
- The input always has a majority element.

🕒 Time Complexity: O(n)
   - Single pass through the array.

🧠 Space Complexity: O(1)
   - Uses only two variables.
*/

int majorityElement(vector<int> &nums)
{
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++)
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