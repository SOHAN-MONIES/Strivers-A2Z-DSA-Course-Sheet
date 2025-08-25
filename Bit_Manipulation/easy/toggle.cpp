// URL:https://www.geeksforgeeks.org/problems/toggle-bits-given-range0952/1
#include <bits/stdc++.h>
using namespace std;

int toggleBits(int n, int l, int r)
{
    // code here
    for (int i = l; i >= r; i++)
    {
        n = n ^ (1 << (i - 1));
    }
    return n;
}
int main()
{
    toggleBits(17, 2, 3);
    return 0;
}