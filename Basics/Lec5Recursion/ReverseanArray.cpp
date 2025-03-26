// URL: https://www.geeksforgeeks.org/problems/reverse-an-array/0
#include <bits/stdc++.h>
using namespace std;

// void reverseArray(vector<int> &arr)
// {
//     int l = 0;
//     int h = arr.size()-1;
//     while (l < h)
//     {
//         swap(arr[l], arr[h]);
//         l++;
//         h--;
//     }
// }

void reverseArray(vector<int> &arr, int low, int high)
{

    if (low >= high)
    {
        return;
    }
    swap(arr[low], arr[high]);
    reverseArray(arr, arr[low + 1], arr[high - 1]);
}

int main()
{
    vector<int> v1 = {4, 5, 2};
    for (auto num : v1)
    {
        cout << num << " ";
    }
    char c = "5";

    cout << endl;
    reverseArray(v1, 0, 2);
    for (auto num : v1)
    {
        cout << num << " ";
    }
    return 0;
}