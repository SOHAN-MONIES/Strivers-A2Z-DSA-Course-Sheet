// URL:
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int countFreq(vector<int> &arr, int target)

{
    return ((upper_bound(arr.begin(), arr.end(), target) - arr.begin()) - (lower_bound(arr.begin(), arr.end(), target) - arr.begin()));
}

int main()
{
    vector<int> v1 = {2, 2, 2, 3, 4};
    cout << countFreq(v1, 2);
    return 0;
}