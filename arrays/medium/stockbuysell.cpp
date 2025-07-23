// URL:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
using namespace std;
/*
Algorithm: Max Profit (Buy and Sell Stock Once)

Time Complexity: O(n) – Traverse the prices array once
Space Complexity: O(1) – Uses only constant extra space

1. Initialize 'mini' with prices[0]
   - This keeps track of the lowest price seen so far.

2. Initialize 'max_profit' as 0
   - This stores the maximum profit that can be achieved.

3. Loop through the array from index 1 to n - 1:
   a. Calculate current profit = prices[i] - mini
      - This is the profit if the stock was bought at 'mini' and sold at prices[i]

   b. If profit > max_profit, update max_profit
      - Always store the best possible profit

   c. Update mini = min(mini, prices[i])
      - Keep updating the minimum price encountered so far

4. Return max_profit as the final result
*/

int maxProfit(vector<int> &prices)
{
   int n = prices.size();
   int max_profit = 0;
   int mini = prices[0];
   for (int i = 1; i < n; i++)
   {
      int profit = prices[i] - mini;
      if (profit > max_profit)
      {
         max_profit = profit;
      }
      mini = min(mini, prices[i]);
   }
   return max_profit;
}
int main()
{
   vector<int> v1 = {7, 6, 4, 3, 1};
   cout << maxProfit(v1);
   return 0;
}