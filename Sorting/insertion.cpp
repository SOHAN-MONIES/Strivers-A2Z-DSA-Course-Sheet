// URL:https://www.geeksforgeeks.org/problems/insertion-sort/1
#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(arr);
    printArr(arr);
    return 0;
}