// URL: https://leetcode.com/problems/two-sum/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// BRUTEFORCE APROACH
//  vector<int> twoSum(vector<int> &nums, int target)
//  {
//      vector<int> ans;
//      for (int i = 0; i < nums.size(); i++)
//      {
//          for (int j = i + 1; j < nums.size(); j++)
//          {
//              if (nums[i] + nums[j] == target)
//              {
//                  ans.push_back(i);
//                  ans.push_back(j);
//              }
//          }
//      }
//      return ans;
//  }
// Better
vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mpp;
    vector<int> v1;
    for (int i = 0; i < nums.size(); i++)
    {
        int a = nums[i];
        int more = target - nums[i];
        if (mpp.find(more) != mpp.end())
        {
            v1.push_back(i);
            v1.push_back(mpp[more]);
        }
        mpp[a] = i;
    }
    return v1;
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