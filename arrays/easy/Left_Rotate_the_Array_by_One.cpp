// URL:- https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void rotate(vector<int> &arr)
{
    int n = arr.size();
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    for (auto num : arr)
    {
        cout << num;
    }
}

int main()
{
    vector<int> v1 = {1, 2, 4};
    rotate(v1);
    return 0;
}