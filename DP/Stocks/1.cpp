// URL:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxProfit = 0;
    int sell_high = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (prices[i] > sell_high)
        {
            sell_high = prices[i];
            continue;
        }
        int profit = sell_high - prices[i];

        maxProfit = max(maxProfit, profit);
    }
    return maxProfit;
}
int main()
{
    vector<int> stocks = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(stocks);
    return 0;
}