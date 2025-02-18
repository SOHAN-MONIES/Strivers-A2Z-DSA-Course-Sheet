// URL:
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int lower__bound(vector<int> a, int x)
{
    int n = a.size();
    int l = 0;
    int h = n - 1;
    int ans = n;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (a[m] >= x)
        {
            ans = m;
            h = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}

int upper__bound(vector<int> a, int x)
{
    int n = a.size();
    int l = 0;
    int h = n - 1;
    int ans = n;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (a[m] > x)
        {
            ans = m;
            h = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}

int main()
{
    vector<int> v1 = {1, 2, 4, 6, 7, 8};
    cout << lower__bound(v1, 6) << endl;
    cout << upper__bound(v1, 6) << endl;
    cout << distance(v1.begin(), lower_bound(v1.begin(), v1.end(), 6))<<endl;
    cout << distance(v1.begin(), upper_bound(v1.begin(), v1.end(), 6));
    return 0;
}