// URL:
#include <bits/stdc++.h>
using namespace std;

long long findMaxSubarraySum(vector<int> &arr, long long x)
{
    long long maxSum = 0;
    long long sum = 0;
    int l = 0;
    int r = 0;
    while (r < arr.size())
    {

        if (sum <= x)
        {
            sum += arr[r];
            if (sum <= x)
            {
                maxSum = max(sum, maxSum);
                r++;
            }

            else
            {

                sum -= arr[l];
                l++;
            }
        }
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {46, 22, 71, 76, 19};
    cout << findMaxSubarraySum(arr, 73);
    return 0;
}