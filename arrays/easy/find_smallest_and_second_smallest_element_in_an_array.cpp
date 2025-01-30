// URL:- https://www.geeksforgeeks.org/problems/find-the-smallest-and-second-smallest-element-in-an-array3226/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> minAnd2ndMin(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int min = arr[0];
    vector<int> v1;
    v1.push_back(min);
    int smin = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != min)
        {
            smin = arr[i];
            v1.push_back(smin);
            break;
        }
    }
    if (smin == 0)
    {
        vector<int> v2 = {-1};
        return v2;
    }
    else
        return v1;
}

int main()
{
    return 0;
}