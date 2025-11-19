// URL: https://www.geeksforgeeks.org/problems/geeks-training/1
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Ninja Training (Dynamic Programming)

Problem:
- There are N days and 3 tasks per day.
- Each task gives some points.
- You can't perform the same task on two consecutive days.
- Maximize total points.

Tasks: 0, 1, 2
`arr[day][task]` → points.

We use “last” = the task done on previous day:
- last = 0, 1, 2 → task index
- last = 3 → special value meaning "no restriction" (used for day 0)

-------------------------------------------------
1️⃣ Recursive + Memoization (Top-Down)

Function f(day, last):
- Base case:
  - If day == 0:
      Choose the best among tasks 0,1,2 except 'last'
- If dp[day][last] already computed → return it
- Otherwise:
      Try all tasks except 'last'
      Recursively compute:
          arr[day][task] + f(day-1, task)
      Take the best (maximum)

Answer = f(n-1, 3)

Time Complexity: O(n × 4 × 3)
Space Complexity: O(n × 4) + recursion stack

-------------------------------------------------
2️⃣ Tabulation (Bottom-Up)

Steps:
1. Create dp[n][4]
2. Base initialization for day 0:
      dp[0][0] = max(arr[0][1], arr[0][2])
      dp[0][1] = max(arr[0][0], arr[0][2])
      dp[0][2] = max(arr[0][0], arr[0][1])
      dp[0][3] = max(arr[0][0], arr[0][1], arr[0][2])
3. For each day = 1 to n-1:
       For each last = 0..3:
           dp[day][last] = max of:
               arr[day][task] + dp[day-1][task]
               (for all tasks != last)
4. Answer = dp[n-1][3]

Time Complexity: O(n × 4 × 3)
Space Complexity: O(n × 4)

-------------------------------------------------
3️⃣ Space Optimized DP

Idea:
- Only previous day is needed.
- Use `prev[4]` and `curr[4]`.

Steps:
1. Fill prev[] for day 0
2. For every new day:
      Compute curr[last] using prev[]
3. After each day: prev = curr
4. Final answer = prev[3]

Time Complexity: O(n × 4 × 3)
Space Complexity: O(4) = O(1)

-------------------------------------------------
✅ Intuition:
- Each day depends only on:
      - the task chosen today
      - the best score from previous day where previous task != current task
- 'last' ensures we don’t pick the same task consecutively.
- Memoization avoids recalculating the same states.
- Tabulation builds solution iteratively.
- Space optimization stores only necessary info.

-------------------------------------------------
*/

int f(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (dp[day][last] != -1)
    {
        // cout<<day<<" "<<last<<endl;
        return dp[day][last];
    }
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, arr[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = arr[day][task] + f(day - 1, task, arr, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int maximumPoints(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(arr.size(), vector<int>(4, -1));
    return f(n - 1, 3, arr, dp);
}

int maximumPointsT(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(arr.size(), vector<int>(4, -1));
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][1], arr[0][0]);
    dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int points = arr[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], points);
                }
            }
        }
    }

    return dp[n - 1][3];
}

int maximumPointsSpaceOptimized(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<int> prev(4, 0);
    prev[0] = max(arr[0][1], arr[0][2]);
    prev[1] = max(arr[0][0], arr[0][2]);
    prev[2] = max(arr[0][1], arr[0][0]);
    prev[3] = max({arr[0][0], arr[0][1], arr[0][2]});
    for (int day = 1; day < n; day++)
    {
        vector<int> curr(4, 0);
        for (int last = 0; last < 4; last++)
        {
            curr[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int points = arr[day][task] + prev[task];
                    curr[last] = max(curr[last], points);
                }
            }
        }
        prev = curr;
    }
    return prev[3];
}
int main()
{
    vector<vector<int>> arr = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90},
        {15, 25, 35}};
    cout << maximumPointsSpaceOptimized(arr);
    return 0;
}