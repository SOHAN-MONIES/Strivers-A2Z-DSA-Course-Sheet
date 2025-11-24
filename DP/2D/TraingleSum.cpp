// URL:https://leetcode.com/problems/triangle/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Minimum Path Sum in a Triangle (Dynamic Programming)

Problem:
Given a triangle array, return the minimum total path sum
from top to bottom. At each step, you may move to:
- directly below  (i+1, j)
- diagonal right  (i+1, j+1)

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Function f(i, j):
- Base Case:
    If i is last row → return triangle[i][j]
- If already computed → return dp[i][j]
- Recurrence:
    down = triangle[i][j] + f(i+1, j)
    diag = triangle[i][j] + f(i+1, j+1)
- Return min(down, diag)

Time Complexity: O(n²)
Space Complexity: O(n²) + recursion stack

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up DP)

Steps:
1. Create dp[n][n] initialized to 0
2. Fill last row: dp[n-1][j] = triangle[n-1][j]
3. Loop i from n-2 → 0:
       For j from 0 → i:
            down = triangle[i][j] + dp[i+1][j]
            diag = triangle[i][j] + dp[i+1][j+1]
            dp[i][j] = min(down, diag)
4. Answer = dp[0][0]

Time Complexity: O(n²)
Space Complexity: O(n²)

-------------------------------------------------
3️⃣ Space Optimized

Idea:
- Only store next row results instead of the full dp matrix
- Use `next[]` and `curr[]` arrays

Steps:
1. Initialize next[] = last row of triangle
2. For i from n-2 → 0:
      For j from 0 → i:
           curr[j] = triangle[i][j] + min(next[j], next[j+1])
      next = curr
3. Return next[0]

Time Complexity: O(n²)
Space Complexity: O(n)

-------------------------------------------------
🎯 Intuition:
Start from the bottom and compute the best possible choice upward,
because every cell depends only on two cells below.

-------------------------------------------------
*/

int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == triangle.size() - 1)
    {
        return triangle[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int down = triangle[i][j] + f(i + 1, j, triangle, dp);
    int diag = triangle[i][j] + f(i + 1, j + 1, triangle, dp);
    return dp[i][j] = min(down, diag);
}

int minimumTotal_Memoizatiob(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, 0, triangle, dp);
}

int minimumTotal_Tabulation(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diag = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diag);
        }
    }
    return dp[0][0];
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> next(n, 0);
    for (int j = 0; j < n; j++)
    {
        next[j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j <= i; j++)
        {
            int down = triangle[i][j] + next[j];
            int diag = triangle[i][j] + next[j + 1];
            curr[j] = min(down, diag);
        }
        next = curr;
    }
    return next[0];
}
int main()
{
    vector<vector<int>> grid = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    cout << minimumTotal(grid);
    return 0;
}