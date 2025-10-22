// URL:
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Fibonacci Number (Dynamic Programming)

Problem:
- Compute the nth Fibonacci number:
  F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for n >= 2.

-------------------------------------------------
1️⃣ Recursive with Memoization (Top-Down):

Steps:
1. Create a dp array of size n+1 initialized with -1.
2. Base case: if n <= 1, return n.
3. If dp[n] is already computed, return dp[n].
4. Otherwise, compute dp[n] = fib(n-1) + fib(n-2) and store it.
5. Return dp[n].

Time Complexity: O(n)
Space Complexity: O(n) for recursion stack + O(n) for dp array

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up):

Steps:
1. Create dp array of size n+1.
2. Initialize dp[0] = 0, dp[1] = 1.
3. Loop i = 2 to n:
   - dp[i] = dp[i-1] + dp[i-2]
4. Return dp[n]

Time Complexity: O(n)
Space Complexity: O(n)

-------------------------------------------------
3️⃣ Space Optimized Iterative:

Steps:
1. If n <= 1, return n.
2. Initialize two variables: prev2 = 0, prev1 = 1.
3. Loop i = 2 to n:
   - curr = prev1 + prev2
   - prev2 = prev1
   - prev1 = curr
4. Return prev1

Time Complexity: O(n)
Space Complexity: O(1)

-------------------------------------------------
✅ Intuition:
- Recursive is simple but slow due to overlapping subproblems.
- Memoization avoids recomputation.
- Tabulation builds results iteratively.
- Space optimization only keeps the last two Fibonacci numbers.
*/

// memoization
int fib(int n, vector<int> &dp)
{
    if (n <= 1)
    {

        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}
// tabulation
int fib(int n)
{
    if (n <= 1)
        return n;

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
// efficient
int fib(int n)
{
    if (n <= 1)
        return n;

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{

    vector<int> dp(100, -1);
    cout << fib(48, dp);
    return 0;
}