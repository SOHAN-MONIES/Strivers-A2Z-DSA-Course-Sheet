// URL:
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 1};
    vector<int> hash(100, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        hash[arr[i]]++;
    }
    cout << hash[6];
    return 0;
}
