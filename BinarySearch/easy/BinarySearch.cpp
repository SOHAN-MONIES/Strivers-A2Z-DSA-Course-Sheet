#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &a, int t)
{
    int n = a.size();
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (a[m] == t)
            return m;
        else if (t > a[m])
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

int main()
{
    vector<int> v1 = {1, 2, 4, 6, 90};
    cout << binary_search(v1, 1);
}