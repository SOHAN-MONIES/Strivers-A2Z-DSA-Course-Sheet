// URL: https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
#include <bits/stdc++.h>
using namespace std;

bool checkKthBit(int n, int k)
{
    int res = (n >> k) & 1;
    if (res == 0)
        return false;
    else
        return true;
}

int main() {
    cout<<checkKthBit(17619, 16);
    return 0;
}