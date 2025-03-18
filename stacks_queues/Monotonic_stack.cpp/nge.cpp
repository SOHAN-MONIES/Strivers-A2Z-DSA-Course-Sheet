// URL:
#include <bits/stdc++.h>
using namespace std;
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