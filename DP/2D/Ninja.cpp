// URL: https://www.geeksforgeeks.org/problems/geeks-training/1
#include <bits/stdc++.h>
using namespace std;
int f(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, arr[0][i]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = arr[day][i] + f(day - 1, i, arr, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int maximumPoints(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(arr.size(), vector<int>(4, -1));
    return f(n - 1, 3, arr, dp);
}

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}};
    cout << maximumPoints(arr);
    return 0;
}