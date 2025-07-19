// URL:https://leetcode.com/problems/missing-number/description/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm to Find Missing Number Using XOR

1. XOR all indices from 0 to n-1 with all elements in the array.
2. Due to XOR properties, duplicates cancel out (a ^ a = 0).
3. We're missing one number in [0, n], so include 'n' at the end: res ^ n.
4. The result will be the missing number.
*/

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