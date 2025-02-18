// URL: https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1?page=1&category=Binary%20Search&sortBy=submissions
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> find(vector<int> &arr, int x)
{
    vector<int> v1;
    auto itl = lower_bound(arr.begin(), arr.end(), x);
    auto itu = upper_bound(arr.begin(), arr.end(), x);
    if (itl == arr.end())
    {
        v1.push_back(-1);
        v1.push_back(-1);
    }
    else if (*itl != x)
    {
        v1.push_back(-1);
        v1.push_back(-1);
    }
    int d1 = distance(arr.begin(), itl);
    int d2 = distance(arr.begin(), itu) - 1;
    v1.push_back(d1);
    v1.push_back(d2);
    return v1;
}

int main()
{

    return 0;
}