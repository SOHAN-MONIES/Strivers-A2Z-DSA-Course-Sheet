// URL:
#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(vector<int> &arr, int k)
{
    // code here
    int maxSum = 0;
    int sum = 0;
    int l = 0;
    int r = l + k - 1;
    for (int i = l; i <= r; i++)
    {
        sum += arr[i];
    }
    maxSum = sum;
    while (r < arr.size())
    {
        sum -= arr[l];
        l++;
        r++;
        sum += arr[r];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    cout << maxSubarraySum(arr, 1);
    return 0;
}