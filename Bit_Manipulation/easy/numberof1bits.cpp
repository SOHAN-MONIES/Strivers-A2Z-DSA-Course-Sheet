// URL:https://leetcode.com/problems/number-of-1-bits/
#include <bits/stdc++.h>
using namespace std;

int findBinaryDigits(int n)
{
    int ans = 0;
    while (n != 0)
    {
        n = n >> 1; // divide by 2 (binary)
        ans++;
    }
    return ans;
}

int hammingWeight(int n)
{
    int cnt = 0;
    int digits = findBinaryDigits(n);

    while (digits--)
    {
        if (n & (1 << (digits)))
            cnt++;
    }
    return cnt;
}
int main()
{
    cout << hammingWeight(11);
    return 0;
}