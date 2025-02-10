// URL: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int longestSubarray(vector<int> &arr, int k)
{
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int maxLen = 0;
    int n = arr.size();
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
            sum += arr[right];
    }
    return maxLen;
}
// int findSubArray(vector<int> &arr, int k)
// {
//     vector<vector<int>> v1;
//     int len = 0;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int sum = 0;
//         for (int j = i; j < arr.size(); j++)
//         {
//             sum += arr[j];
//             if (sum == k)
//             {
//                 len = max(len, j - i + 1);
//             }
//         }
//     }
//     return len;
// }

int main()
{
    vector<int> v3 = {10, 5, 2, 7, 1, -10};
    // cout << longestSubarray(v3, -5);
    cout << longestSubarray(v3, 15);
    return 0;
}