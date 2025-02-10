// URL:https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?page=5&sortBy=submissions
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int countFreq(vector<int> &arr, int target)
{
    unordered_map<int, int> hash;
    for (auto num : arr)
    {
        hash[num]++;
    }
    for (auto num : hash)
    {
        if (num.first == target)
        {
            return num.second;
        }
    }
    return 0;
}

int main()
{
    vector<int> v1 = {1, 1, 2, 2, 2, 2, 3};
    cout << countFreq(v1, 4);

    return 0;
}