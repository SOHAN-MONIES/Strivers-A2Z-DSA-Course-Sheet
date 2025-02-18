// URL:
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxCount = 0;
    int cnt = 0;
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] == 1)
        {
            cnt = j - i + 1;
            if (cnt > maxCount)
            {
                maxCount = cnt;
            }
        }
        else
        {
            i = j + 1;
            cnt = 0;
        }
    }
    return maxCount;
}

int main()
{
    vector<int> v1 = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(v1);
    return 0;
}