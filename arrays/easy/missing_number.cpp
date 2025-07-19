// URL:https://leetcode.com/problems/missing-number/description/
#include <bits/stdc++.h>
using namespace std;
/*
XOR all indices from 0 to n with all elements in the array.
Due to XOR properties, duplicates cancel out, leaving the missing number.
Return res ^ n to include the last index n in the result
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