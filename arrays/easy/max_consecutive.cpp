// URL:https://leetcode.com/problems/max-consecutive-ones/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int cnt = 0;
    int max_cnt = 0;
    for (auto num : nums)
    {
        if (num == 1)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        max_cnt = max(cnt, max_cnt);
    }

    return max_cnt;
}

int main()
{
    vector<int> v1 = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(v1);
    return 0;
}