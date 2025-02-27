// URL: https://www.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1
#include <bits/stdc++.h>
using namespace std;

// double medianOf2(vector<int> &a, vector<int> &b)
// {
//     int n1 = a.size();
//     int n2 = b.size();
//     int i = 0;
//     int j = 0;
//     vector<int> unionArr;
//     while (i < n1 && j < n2)
//     {
//         if (a[i] <= b[j])
//         {
//             unionArr.push_back(a[i]);
//             i++;
//         }
//         else
//         {
//             unionArr.push_back(b[j]);
//             j++;
//         }
//     }
//     while (i < n1)
//     {
//         unionArr.push_back(a[i]);
//         i++;
//     }
//     while (j < n2)
//     {
//         unionArr.push_back(b[j]);
//         j++;
//     }
//     int m = unionArr.size();
//     if (m % 2 == 1)
//     {
//         return (double)unionArr[m / 2];
//     }
//     else
//     {
//         return ((double)unionArr[m / 2] + unionArr[m / 2 - 1]) / 2.0;
//     }
// }
double medianOf2(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();
    if(n1>n2)
        return medianOf2(b, a);
    int l = 0;
    int h = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;
    while (l <= h)
    {
        int mid1 = (l + h) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1<n1)
            r1 = a[mid1];
        if(mid2<n2)
            r2 = b[mid2];
        if(mid1-1>=0)
            l1 = a[mid1 - 1];
        if(mid2-1>=0)
            l2 = b[mid2 - 1];
        if(l1<=r2&&l2<=r1){
            if(n%2==1)
                return max(l1, l2);
            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if(l1>r2){
            h = mid1- 1;
        }
        else if(l2>r1){
            l = mid1+ 1;
        }
    }
    return 0;
}

int main()
{

    return 0;
}