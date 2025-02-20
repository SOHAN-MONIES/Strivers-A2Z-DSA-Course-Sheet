// URL: https://www.geeksforgeeks.org/problems/element-appearing-once2552/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// int singleNonDuplicate(vector<int> &nums)
// {
//     for(auto num:nums){
//         int d1 = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), num)) - 1;
//         int d2= distance(nums.begin(), lower_bound(nums.begin(), nums.end(), num)) ;
//         if(d1-d2==0){
//             return num;
//         }
//     }
//     return -1;
// }

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
    {
        return nums[0];
    }
    if (nums[n - 1] != nums[n - 2])
    {
        return nums[n - 1];
    }
    int l = 1;
    int h = n - 2;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (nums[m] != nums[m + 1] && nums[m] != nums[m - 1])
            return nums[m];
        if (m % 2 == 1 )
     {
         if (nums[m] != nums[m - 1]){
             h = m - 1;
         }
         else
             l = m + 1;
     }
     if (m % 2 == 0)
     {
         if (nums[m] != nums[m - 1])
         {
             l = m + 1;
         }
         else
             h = m - 1;
     }
    }
    return -1;
}

int main()
{
    vector<int> v1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(v1);
    return 0;
}