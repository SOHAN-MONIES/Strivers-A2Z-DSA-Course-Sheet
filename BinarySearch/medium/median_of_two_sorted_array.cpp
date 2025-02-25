// URL: https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1
#include <bits/stdc++.h>
using namespace std;

double medianOf2(vector<int> &a, vector<int> &b)
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
    int m = unionArr.size();
    if (m % 2 == 1)
    {
        return (double)unionArr[m / 2];
    }
    else
    {
        return ((double)unionArr[m / 2] + unionArr[m / 2 - 1]) / 2.0;
    }
}
double medianOf2(vector<int> &a, vector<int> &b) {



}


int main()
{

    return 0;
}