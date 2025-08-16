// URL: https://leetcode.com/problems/set-mismatch/
#include <bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int> nums)
{
    int n = nums.size();
    int So1 = n * (n + 1) / 2;
    int Sd1 = 0;
    int So2 = (n) * (n + 1) * (2 * n + 1) / 6;
    int Sd2 = 0;
    for (int i = 0; i < n; i++)
    {
        Sd1 += nums[i];
        Sd2 += nums[i] * nums[i];
    }
    int X = So1 - Sd1;
    int Y = So2 - Sd2;
    return {(X * X + Y) / X*2, -X + (X * X + Y) / X};
}
int main() {
    vector<int> arr = {1, 2, 2, 4};
    findErrorNums(arr);
    return 0;
}