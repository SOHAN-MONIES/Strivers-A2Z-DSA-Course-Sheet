// URL: https://www.geeksforgeeks.org/problems/insertion-sort/1
#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    int min_index;
    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

void printArr(vector<int> arr)
{
    for (auto num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 30, 9};
    printArr(arr);
    selectionSort(arr);
    printArr(arr);
    return 0;
}