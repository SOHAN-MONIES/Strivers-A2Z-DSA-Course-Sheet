// URL:
#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMinsg(vector<int> &arr)
{
    int mod = (int)(1e9 + 7);
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int minimum = arr[i];
        for (int j = i; j < arr.size(); j++)
        {
            minimum = min(minimum, arr[j]);
            sum = (sum + minimum) % mod;
        }
    }
    return sum;
}

int sumSubarrayMins(vector<int> &arr)
{
    int mod = (int)(1e9 + 7);
    int n = arr.size();
    int sum = 0;
    stack<int> stp;
    stack<int> stn;
    vector<int> pse(n, -1);
    vector<int> nse(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!stp.empty() && arr[stp.top()] >= arr[i])
        {
            stp.pop();
        }
        if (!stp.empty())
        {
            pse[i] = stp.top();
        }
        stp.push(i);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        while (!stn.empty() && arr[stn.top()] >arr[i])
        {
            stn.pop();
        }
        if (!stn.empty())
        {
            nse[i] = stn.top();
        }
        stn.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;
        sum = (sum + arr[i] * right * left) % mod;
    }
    return sum;
}

int main()
{
    vector<int> v1 = {71, 55, 82, 55};
    cout << sumSubarrayMins(v1);
    return 0;
}