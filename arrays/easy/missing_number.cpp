// URL:https://leetcode.com/problems/missing-number/description/
#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        res = res ^ i ^ nums[i];
    }
    return res ^ nums.size();
}
int main()
{

    return 0;
}