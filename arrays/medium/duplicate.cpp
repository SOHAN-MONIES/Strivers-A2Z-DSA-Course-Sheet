// URL:https://leetcode.com/problems/find-the-duplicate-number/
#include <bits/stdc++.h>
using namespace std;
/*
Algorithm: Floyd's Tortoise and Hare (Cycle Detection) – Find the Duplicate Number

Time Complexity: O(n)
   - Each pointer moves at most 2n steps in total (due to the cycle), so linear time.

Space Complexity: O(1)
   - No extra space used, only two pointers.

1. Initialize two pointers 'slow' and 'fast' at the starting position (nums[0]).

2. Phase 1: Detect Intersection Point
   - Move 'slow' one step at a time: slow = nums[slow]
   - Move 'fast' two steps at a time: fast = nums[nums[fast]]
   - Continue until slow == fast (cycle detected)

3. Phase 2: Find Entrance to the Cycle
   - Reset slow to nums[0]
   - Move both slow and fast one step at a time
   - When they meet again, it's the duplicate number

4. Return the value at meeting point (duplicate number)
*/

int findDuplicate(vector<int> &nums)
{
   int slow = nums[0];
   int fast = nums[0];
   do
   {
      slow = nums[slow];
      fast = nums[nums[fast]];
   } while (slow != fast);
   slow = nums[0];
   while (slow != fast)
   {
      slow = nums[slow];
      fast = nums[fast];
   }
   return fast;
}
int main()
{
   vector<int> arr = {1, 3, 2, 3, 4};
   cout << findDuplicate(arr);
   return 0;
}