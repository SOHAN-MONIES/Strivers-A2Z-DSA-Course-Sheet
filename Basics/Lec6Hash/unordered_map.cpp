#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 1};
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}