// URL: https://www.geeksforgeeks.org/problems/search-in-a-rotated-array0959/1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;



int Search(vector<int> vec, int K)
{
    int n = vec.size();
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (vec[m] == K)
            return m;
        if (vec[l] <= vec[m])
        {
            if (K >= vec[l] && K <= vec[m])
                h = m - 1;
            else
                l = m + 1;
        }
        else
        {
            if (K >= vec[m] && K <= vec[h])
                l = m + 1;
            else
                h = m - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v1 = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    cout << Search(v1, 10);
}