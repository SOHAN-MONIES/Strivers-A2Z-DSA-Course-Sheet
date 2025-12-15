// URL:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iiis/
#include <bits/stdc++.h>
using namespace std;

int maxprofit(vector<int> &prices)
{
    if (prices.size() == 0)
    {
        return 0;
    }
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
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        vector<int> partition1(prices.begin(), prices.begin() + i);
        vector<int> partition2(prices.begin() + i, prices.end());
        int profit1 = maxprofit(partition1);
        int profit2 = maxprofit(partition2);
        int profit = profit1 + profit2;
        ans = max(ans, profit);
    }

    return ans;
}
int main()
{
    vector<int> stocks = {1, 2, 3, 4, 5};
    cout << maxProfit(stocks);
    return 0;
}