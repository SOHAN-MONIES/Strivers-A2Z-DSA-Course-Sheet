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

int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int current_sum = 0;
    for (auto num : nums)
    {
        current_sum = max(num, current_sum + num);
        maxSum = max(maxSum, current_sum);
    }
    return maxSum;
}

int main()
{
    vector<int> v1 = {4, 3, 1, 5, 6};
    cout << maxSubArray(v1);
    // vector<int> v2 = maxSubArraywithaddress(v1);
    // for(auto num:v2){
    //     cout << num;
    // }
    return 0;
}