// URL: https://www.geeksforgeeks.org/problems/quick-sort/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}

void quicksort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int pi = partition(nums, low, high);
        quicksort(nums, low, pi - 1);
        quicksort(nums, pi + 1, high);
    }
}
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
    cout << "Sorted array: ";
    printArray(v1, n);
}