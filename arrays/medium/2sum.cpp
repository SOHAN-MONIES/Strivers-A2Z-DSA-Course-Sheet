// URL: https://leetcode.com/problems/two-sum/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
   ✅ Algorithm (Two Sum using unordered_map):

   1. Initialize an empty unordered_map to store value → index.
   2. Iterate through the array:
      - For each element nums[i], compute the complement: target - nums[i].
      - Check if the complement exists in the map:
        - If found, return the pair of indices [map[complement], i].
      - Otherwise, store the current value and index in the map: map[nums[i]] = i.
   3. Return the result vector containing the two indices.

   🕒 Time Complexity: O(n)
   - Each element is visited once.
   - unordered_map operations (insert/find) take O(1) average time.

   🧠 Space Complexity: O(n)
   - Up to n elements are stored in the unordered_map.
   */

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        int candidate_element = target - nums[i];
        auto it = mpp.find(candidate_element);
        if (it != mpp.end())
        {
            res.push_back(i);
            res.push_back(it->second);
            break;
        }
        mpp.insert({nums[i], i});
    }
    return res;
}

// Two pointer approach
bool twoSumbool(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        if (arr[left] + arr[right] == target)
            return true;
        else if (arr[left] + arr[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return false;
}
int main()
{
    vector<int> v1 = {1, 4, 45, 6, 10, 8};
    cout << twoSumbool(v1, 16);
    // for (auto num : v2)
    // {
    //     cout << num << " ";
    // }

    return 0;
}