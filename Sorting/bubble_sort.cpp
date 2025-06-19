// URL: https://www.geeksforgeeks.org/problems/bubble-sort/1
#include <bits/stdc++.h>
using namespace std;

// PUSH THE MAX TO LAST BY ADJACENT SWAPS
void bubbleSort(vector<int> &arr)
{

    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int swap_flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swap_flag++;
            }
        }
        if (swap_flag == 0)
        {
            break;
        }
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
    bubbleSort(arr);
    printArr(arr);
    return 0;
}