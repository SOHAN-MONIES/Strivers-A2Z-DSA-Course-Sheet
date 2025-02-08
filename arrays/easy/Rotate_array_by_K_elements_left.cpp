// URL:-
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void rotateArr(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n;
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> v3 = {1, 2, 3, 4, 5};
    rotateArr(v3, 2);
    for (auto num : v3)
    {
        cout << num << " ";
    }
    return 0;
}