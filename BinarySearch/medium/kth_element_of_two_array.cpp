// URL: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
#include <bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            unionArr.push_back(a[i]);
            i++;
        }
        else
        {
            unionArr.push_back(b[j]);
            j++;
        }
    }
    while (i < n1)
    {
        unionArr.push_back(a[i]);
        i++;
    }
    while (j < n2)
    {
        unionArr.push_back(b[j]);
        j++;
    }
    return unionArr[k - 1];
}

int main()
{

    return 0;
}