// URL: https://leetcode.com/problems/find-peak-element/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// BRUTEFORCE
// int findPeakElement(vector<int> &arr)
// {

//     int j, k;
//     int n = arr.size();
//     if(n==1){
//         return 0;
//     }

//     for (int i = 0; i < n ; i++)
//     {
//         j = i - 1;
//         k = i + 1;
//         if (i == 0)
//         {
//             if (arr[i] > arr[k])
//                 return  i;
//         }
//        else if (i == arr.size() - 1)
//         {
//             if (arr[i] > arr[j])
//                 return i;
//         }
//         else{
//         if (arr[i] > arr[j] && arr[i] > arr[k])
//         {
//             return i;
//         }
//         }
//     }
//     return -1;
// }

// O(N)
//  int findPeakElement(vector<int> &arr){
//      for (int i = 0; i < arr.size(); i++) {
//          if((i==0||arr[i-1]<arr[i])&&(i==arr.size()-1||arr[i]>arr[i+1]))
//              return i;
//      }
//  }

// O(N)

int findPeakElement(vector<int> &arr)
{
    if (arr.size() == 1)
        return 0;
    int l = 0;
    int h = arr.size() - 1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if ((m == 0 || arr[m] > arr[m - 1]) && (m == arr.size() - 1 || arr[m] > arr[m + 1]))
            return m;
        if (arr[m] > arr[m + 1])
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 1, 5, 78, 3};
    cout << findPeakElement(v1);
    return 0;
}