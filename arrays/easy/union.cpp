// URL:-
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    int i = 0;
    int n1 = a.size();
    int j = 0;
    int n2 = b.size();
    vector<int> unionArr;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j]) 
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }
    return unionArr;
}

int main()
{
    vector<int> v1 = {1, 1, 2, 3, 4, 5};
    vector<int> v2 = {-1, 0, 1, 2, 3, 4, 5, 6};
    vector<int> v3 = findUnion(v1, v2);
    for (auto num : v3)
    {
        cout << num << " ";
    }
    return 0;
}