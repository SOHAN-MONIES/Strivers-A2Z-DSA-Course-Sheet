// URL: https://leetcode.com/problems/kth-missing-positive-number/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// int findKthPositive(vector<int> &arr, int k)
// {
//     for(int num:arr){
//         if(num<=k)
//             k++;
//         else 
//             break;
//     }
//     return k;
// }

int findKthPositive(vector<int> &arr, int k){
    int l = 0;
    int h = arr.size() - 1;
    while (l<=h){
        int m = (l + h) / 2;
        int missing = arr[m] - (m + 1);
        if(missing>k){
            h = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return l+1;
}

    int main()
{
    vector<int> v1 = {2, -3, 4, 1, 1, 7};
    cout<<findKthPositive(v1, 3);
   // cout << missingNumber(v1);
    return 0;
}