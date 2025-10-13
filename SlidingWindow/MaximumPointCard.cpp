// URL:
#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int maxSum = 0;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += cardPoints[i];
    }
    maxSum = sum;
    for (int i = 0; i < k; i++)
    {
        sum -= cardPoints[k - i - 1];
        sum += cardPoints[n - i - 1];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 1};
    cout << maxScore(arr, 3);
    return 0;
}