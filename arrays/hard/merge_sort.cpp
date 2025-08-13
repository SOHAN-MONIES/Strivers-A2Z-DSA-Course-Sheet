// URL:
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
            temp.push_back(arr[left]);
            left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[low + i] = temp[i];
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    int mid = (l + r)/2;
    if (l == r)
        return;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    vector<int> arr = {81,23,1,2,3,1,22,346,62};
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
    mergeSort(arr, 0, arr.size() - 1);
    for (int ele : arr)
        cout
            << ele << " ";
    cout << endl;
    return 0;
}