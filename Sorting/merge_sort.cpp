// URL: https://www.geeksforgeeks.org/problems/merge-sort/1
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}

vector<int> mergeSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return nums;
    int mid = (low + high) / 2;
    mergeSort(nums, low, mid);      // left half
    mergeSort(nums, mid + 1, high); // right half
    merge(nums, low, mid, high);
    return nums;
}

int main()
{

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto num : arr)
    {
        cout << num << " ";
    }
}