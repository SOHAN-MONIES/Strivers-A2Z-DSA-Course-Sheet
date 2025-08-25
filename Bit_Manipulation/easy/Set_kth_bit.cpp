// URL: https://www.geeksforgeeks.org/problems/set-kth-bit3724/1
#include <bits/stdc++.h>
using namespace std;
int setKthBit(int n, int k)
{
    int res = n | (1 << k);
    return res;
}

int main() {
    
    return 0;
}