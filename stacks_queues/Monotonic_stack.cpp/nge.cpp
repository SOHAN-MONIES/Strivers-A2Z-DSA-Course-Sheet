// URL:
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Next Greater Element (Right Side)

Problem:
For each element in the array, find the next element to the RIGHT
that is strictly greater.
If no such element exists → return -1 for that index.

Example:
arr = [4, 5, 2, 25]
NGE = [5, 25, 25, -1]

-------------------------------------------------
1️⃣ Monotonic Stack Approach (Traverse from Right → Left)

Why from right to left?
- Because NGE is searched on the right side.
- A decreasing stack efficiently stores candidates for NGE.

Steps:
1. Create an empty stack.
2. Traverse array from rightmost index down to 0:
   - While stack is not empty AND stack.top() <= arr[i]:
         pop the stack (useless elements)
   - If stack becomes empty → NGE[i] = -1
     Else → NGE[i] = stack.top()
   - Push arr[i] onto the stack (it may be NGE for someone to the left)

-------------------------------------------------
Time Complexity: O(n)
- Each element is pushed and popped at most once.

Space Complexity: O(n)
- Stack + output array.

-------------------------------------------------
Intuition:
Maintain a stack of "useful" greater elements.
For each element, remove all smaller elements to its right,
so only the next greater candidate remains on top.
-------------------------------------------------
*/

// Bruteforce
//  vector<int> nextLargerElement(vector<int> &arr)
//  {
//      vector<int> ansvector(arr.size(), 0);
//      for (int i = 0; i < arr.size(); i++)
//      {
//          for (int j = i + 1; j < arr.size(); j++)
//          {
//              if (arr[j] > arr[i])
//              {
//                  ansvector[i] = (arr[j]);
//                  break;
//              }
//          }
//          if (ansvector[i] == 0)
//          {
//              ansvector[i] = -1;
//          }
//      }
//      return ansvector;
//  }

vector<int> nextLargerElement(vector<int> &arr)
{
    vector<int> nge(arr.size());
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    // Create an unordered_map to store the next greater element for each number in nums2
    unordered_map<int, int> nge_map;

    // Stack to help find the next greater element for each element in nums2
    stack<int> st;

    // Traverse nums2 from right to left to calculate the next greater element for each number
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        // While the stack is not empty and the top of the stack is less than or equal to nums2[i],
        // pop the elements as they can't be the next greater element for nums2[i]
        while (!st.empty() && st.top() <= nums2[i])
        {
            st.pop();
        }

        // If the stack is empty, there is no next greater element for nums2[i], so map it to -1
        if (st.empty())
        {
            nge_map[nums2[i]] = -1;
        }
        else
        {
            // Otherwise, the next greater element for nums2[i] is the top element of the stack
            nge_map[nums2[i]] = st.top();
        }

        // Push the current element onto the stack so it can be the next greater element for the elements to its left
        st.push(nums2[i]);
    }

    // Result vector to store the next greater element for each element in nums1
    vector<int> result;

    // For each element in nums1, retrieve its next greater element from the map
    for (int num : nums1)
    {
        result.push_back(nge_map[num]); // Push the next greater element for num into the result vector
    }

    // Return the result vector
    return result;
}

int main()
{
    vector<int> v1 = {17, 18, 5, 4, 6, 1};
    vector<int> v2 = nextLargerElement(v1);
    for (auto num : v2)
    {
        cout << num << " ";
    }
    return 0;
}