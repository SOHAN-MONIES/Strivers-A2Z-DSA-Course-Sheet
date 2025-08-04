// URL: https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>
using namespace std;
/*
   Algorithm: Combinatorics – Number of Unique Paths in an m x n Grid

   Problem:
   - You're at the top-left corner of a grid.
   - You can only move right or down.
   - You want to reach the bottom-right corner.
   - Total moves = (m-1) downs + (n-1) rights = (m+n-2) moves.
   - Choose (m-1) moves out of (m+n-2) total moves ⇒ C(m+n-2, m-1)

   Formula: C(N, R) = (N!)/(R! * (N-R)!)
   This code calculates it efficiently without computing factorials.

   Time Complexity: O(min(m, n))
       - The loop runs R times, where R = min(m-1, n-1)

   Space Complexity: O(1)
       - Only a few variables used

   Note: Parameters a and b are unused. You can remove them.
   */

   // BRUTEFORCE RECURSIVE CAN BE OPTIMIZED USING DP
int numberOfPaths(int m, int n,int a=0 ,int b=0)
{

    if (a == m || b == n)
    {
        return 0;
    }
    if (a == m - 1 && b == n - 1)
    {
        return 1;
    }
   return  numberOfPaths(m,n,a, b+1)+numberOfPaths(m,n,a+1,b);
}
int uniquePaths(int m, int n, int a = 0, int b = 0)
{

    int N = m + n - 2;
    int R = m - 1;
    long long int res = 1;
    for (int i = 1; i <= R; i++)
    {
        res = res * (N - R + i) / i;
    }
    return res;
}
int main() {
    cout << numberOfPaths(3, 3);
    return 0;
}