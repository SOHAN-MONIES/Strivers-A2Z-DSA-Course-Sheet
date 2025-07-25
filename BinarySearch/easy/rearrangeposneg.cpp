// URL: https://leetcode.com/problems/rearrange-array-elements-by-sign/
#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> res(nums.size());
    int pos_idx = 0;
    int neg_idx = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            res[pos_idx] = nums[i];
            pos_idx += 2;
        }
        else
        {
            res[neg_idx] = nums[i];
            neg_idx += 2;
        }
    }
    return res;
}

int main() {
    
    return 0;
}