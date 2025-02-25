// URL: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
#include <bits/stdc++.h>
using namespace std;

int studentPossible(vector<int> &arr, int k, int m)
{
    int student = 1;
    int pagestudent = 0;
    for (auto num : arr)
    {
        if (pagestudent + num <= m)
        {
            pagestudent += num;
        }
        else
        {
            student++;
            pagestudent = num;
        }
    }
    return student;
}
int findPages(vector<int> &arr, int k)
{
    if (k > arr.size())
    {
        return -1;
    }

    int l = *max_element(arr.begin(), arr.end());
    int h = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while (l <= h)
    {
        int m = l + (h - l) / 2;

        if (studentPossible(arr, k, m) <=k)
        {

            h = m - 1;
        }
        else 
        {
            l = m + 1;
        }
    }
    return l;
}

int main()
{
    vector<int> v1 = {7,
                      2,
                      5,
                      10,
                      8};
    cout << findPages(v1, 2);
    return 0;
}