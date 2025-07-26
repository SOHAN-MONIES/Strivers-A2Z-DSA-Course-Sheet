// URL: https://leetcode.com/problems/maximum-subarray/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// BRUTEFORCE
//  int maxSubArray(vector<int> &nums)
//  {

//     int n = nums.size();
//     if (n == 1)
//         return nums[0];
//     int maxSum = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = nums[i];
//         for (int j = i + 1; j < n; j++)
//         {
//             sum += nums[j];
//             if (sum > maxSum)
//             {

//                 maxSum = sum;
//             }
//         }
//     }
//     return maxSum;
// }
// BRUTEFORCE
// vector<int> maxSubArraywithaddress(vector<int> &nums)
// {
//     vector<int> v1(2, 0);
//     int n = nums.size();
//     int maxSum = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = nums[i];
//         for (int j = i + 1; j < n; j++)
//         {
//             sum += nums[j];
//             if (sum > maxSum)
//             {
//                 v1[0] = i;
//                 v1[1] = j;
//                 maxSum = sum;
//             }
//         }
//     }
//     return v1;
// }

/*
Algorithm: Kadane's Algorithm – Maximum Subarray Sum

Time Complexity: O(n)
    - Single pass through the array

Space Complexity: O(1)
    - Only two variables used (sum, max_sum)

1. Initialize max_sum to INT_MIN to handle all-negative arrays.
2. Initialize current sum to 0.
3. Traverse the array:
    - Add current element to sum
    - Update max_sum if sum is greater
    - If sum drops below 0, reset it to 0 (we discard the previous subarray)
4. Return max_sum which holds the maximum subarray sum.
*/

int maxSubArray(vector<int> &nums)
{
    int max_sum = INT_MIN; // To handle negative-only arrays
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];              // Add current element
        max_sum = max(max_sum, sum); // Update max_sum if needed
        if (sum < 0)
            sum = 0; // Reset sum if it drops below 0
    }

    return max_sum;
}

int main()
{
    vector<int> v1 = {4, 3, 1, 5, 6};
    cout << maxSubArray(v1);

    return 0;
}