// URL:- https://leetcode.com/problems/rotate-array/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void rotate(vector<int> nums, int k)
{
    int n = nums.size();
    if (k > n)
    {
        k = k % n;
    }
    vector<int> v1 = nums;
    int j = 0;
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + k <= n - 1)
        {
            nums[i + k] = v1[i];
        }
        else
        {
            nums[j] = v1[n - k + a];
            j++;
            a++;
        }
    }
    for (auto num : nums)
    {
        cout << num << " ";
    }
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    //    5 6 7 1 2 3 4
    rotate(v1, 3);
    return 0;
}