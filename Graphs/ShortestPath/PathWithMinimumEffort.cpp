// URL:https://leetcode.com/problems/path-with-minimum-effort/description/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Minimum Effort Path (Dijkstra on 2D Grid)

Problem:
- Given a 2D grid of heights, move from top-left (0,0) to bottom-right (n-1,m-1).
- You can move in 4 directions: up, down, left, right.
- Effort between two adjacent cells = |heights[r1][c1] - heights[r2][c2]|.
- Goal: Find a path where the **maximum effort along the path** is minimized.

Steps:
1. Initialize:
   - distance[i][j] = 1e9 (minimum maximum effort to reach cell (i,j)).
   - distance[0][0] = 0
   - Min-heap priority_queue pq storing pairs {currentEffort, {row, col}}.

2. Dijkstra-like BFS:
   - While pq is not empty:
     - Pop {diff, {row, col}}.
     - If (row,col) is destination → return diff.
     - For each of 4 directions:
         - Compute new row, col.
         - Check bounds.
         - Compute newEffort = max(diff, abs(heights[row][col] - heights[nrow][ncol]))
         - If newEffort < distance[nrow][ncol]:
             - Update distance[nrow][ncol] = newEffort
             - Push {newEffort, {nrow, ncol}} into pq

3. If pq empties without reaching destination → return -1 (theoretically unreachable).

⚠️ Assumptions:
- Grid has at least one cell.
- Heights are non-negative integers.

🕒 Time Complexity: O(N*M*log(N*M))
   - N*M cells, each cell pushed/popped from pq at most once.
   - Each operation takes log(N*M) for priority queue.

🧠 Space Complexity: O(N*M)
   - distance matrix + priority queue.
*/

int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> distance(n, vector<int>(m, 1e9));
    distance[0][0] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        auto [row, col] = it.second;
        if (row == n - 1 && col == m - 1)
            return diff;
        for (int k = 0; k < 4; k++)
        {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                if (newEffort < distance[nrow][ncol])
                {
                    distance[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
            }
        }
    }
    return -1;
}
int main()
{

    return 0;
}