// URL :- https://www.geeksforgeeks.org/problems/binary-search-1587115620/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int binarysearch(vector<int> &arr, int k)
{
    int n = arr.size();
    auto lb = lower_bound(arr.begin(), arr.end(), k);
    if (lb != arr.end() && *lb == k)
    {
        return distance(arr.begin(), lb);
    }
    else
        return -1;
}
int main()
{
    vector<int> v = {1, 1, 1, 1, 2};
    cout << binarysearch(v, 1);
    return 0;
}