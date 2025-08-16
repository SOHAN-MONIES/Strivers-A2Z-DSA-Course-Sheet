//https://leetcode.com/problems/merge-sorted-array/
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    int left = m - 1;
    int right = 0;
    while (left >= 0 && right <= n - 1)
    {
        if (nums1[left] > nums2[right])
        {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    if (n != 0)
    {
        sort(nums1.begin(), nums1.end() - n );
    }
    sort(nums2.begin(), nums2.end());
  
}

int main() {
    vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> b = {2, 5, 6};
    merge(a, 3,b,3);
    return 0;
}