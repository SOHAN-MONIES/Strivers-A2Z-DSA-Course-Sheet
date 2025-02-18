// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// int maxProfit(vector<int> &prices)
// {
//     int diff = 0;
//     for (int i = 0; i < prices.size(); i++)
//     {
//         for (int j = i + 1; j < prices.size(); j++)
//         {
//             diff = max(diff, prices[j] - prices[i]);
//         }
//     }
//     return diff;
// }

void maxProfit(vector<int> &prices)
{
    map<int, int> mpp;
    for (int i = 0; i < prices.size(); i++)
    {
        mpp[prices[i]] = i;
    }
    for (auto it : mpp)
    {
        cout << it.first << " " << it.second;
    }
}

int main()
{
    vector<int> v1 = {7, 1, 5, 3, 6, 4};
    maxProfit(v1);
    // vector<int> v2 = maxSubArraywithaddress(v1);
    // for(auto num:v2){
    //     cout << num;
    // }
    return 0;
}