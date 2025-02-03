// URL: https://www.geeksforgeeks.org/problems/binary-search-1587115620/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{

    return 0;
}