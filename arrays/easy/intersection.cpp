// URL:- https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-array-1587115620/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> intersection1(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0;
    int j = 0;
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> interArr;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            if (interArr.size() == 0 || interArr.back() != arr1[i]) // Check for duplicates
            {
                interArr.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    return interArr;
}

int main()
{
    vector<int> v1 = {1, 1, 2, 3, 4, 5};
    vector<int> v2 = {-1, 0, 1, 2, 3, 4, 5, 6};
    vector<int> v3 = intersection1(v1, v2);
    for (auto num : v3)
    {
        cout << num << " ";
    }
    return 0;
}