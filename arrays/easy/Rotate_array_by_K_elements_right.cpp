// URL:- https://leetcode.com/problems/rotate-array/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.begin(), nums.end());
}

int main()
{
    vector<int> v3 = {1, 2, 3, 4, 5};
    rotate(v3, 2);
    for (auto num : v3)
    {
        cout << num << " ";
    }
    return 0;
}