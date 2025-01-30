// URL:- https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int largest(vector<int> &arr)
{
    int max = arr[0];
    for (auto num : arr)
    {
        if (max < num)
            max = num;
    }
    return max;
}

int main()
{

    return 0;
}