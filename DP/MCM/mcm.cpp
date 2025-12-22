// URL:https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Matrix Chain Multiplication (Dynamic Programming)

Problem:
You are given an array `arr` of size n where:
- The i-th matrix has dimensions: arr[i-1] × arr[i]

Your task is to find the **minimum number of scalar multiplications**
needed to multiply the chain of matrices.

-------------------------------------------------
State Definition:

f(i, j):
- Minimum cost to multiply matrices from index i to j
- Matrices involved:
      Ai × Ai+1 × ... × Aj

-------------------------------------------------
Base Case:
- If i == j:
      Only one matrix → no multiplication needed
      return 0

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down DP)

Transition:
Try every possible partition point `k` where:
- i ≤ k < j

For each partition:
Left subproblem  → f(i, k)
Right subproblem → f(k+1, j)
Cost of multiplying results:
      arr[i-1] × arr[k] × arr[j]

Total cost:
steps =
    arr[i-1] * arr[k] * arr[j]
    + f(i, k)
    + f(k+1, j)

Choose minimum over all k.

Memoization:
- If dp[i][j] already computed → return it

-------------------------------------------------
Initial Call:
f(1, n-1)

-------------------------------------------------
Time Complexity:
O(n³)
- n² states
- Each state tries up to n partitions

-------------------------------------------------
Space Complexity:
O(n²) + recursion stack

-------------------------------------------------
🎯 Intuition:
- Matrix multiplication is associative
- Different parenthesizations lead to different costs
- Try all partition points and pick the minimum
- DP avoids recomputation of overlapping subproblems

-------------------------------------------------
*/

int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr)
{

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(1, n - 1, arr, dp);
}
int main()
{

    return 0;
}