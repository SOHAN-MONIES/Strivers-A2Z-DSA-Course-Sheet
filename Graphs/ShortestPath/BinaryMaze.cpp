// URL:https://leetcode.com/problems/shortest-path-in-binary-matrix/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Shortest Path in Binary Matrix (8-direction BFS)

Problem:
- Given an n x n binary matrix `grid`:
  - 0 = open cell, 1 = blocked cell
- Find the shortest path from top-left (0,0) to bottom-right (n-1,n-1).
- You can move in 8 directions (including diagonals).
- Return the length of the shortest path or -1 if no path exists.

Steps:
1. Edge cases:
   - If start or end cell is blocked → return -1.
   - If start == end and it's open → return 1.

2. Initialize:
   - Queue q1 storing {currentPathLength, {row, col}}.
   - distance matrix to track shortest distance to each cell, initialized to 1e9.
   - distance[start] = 0
   - Direction arrays for 8 movements:
     - delRow = {-1,-1,-1,0,1,1,1,0}
     - delCol = {-1,0,1,1,1,0,-1,-1}

3. BFS:
   - While queue not empty:
     - Pop front element {dist, {row, col}}.
     - For each of 8 directions:
         - Compute nrow = row + delRow[k], ncol = col + delCol[k]
         - Check bounds and that grid[nrow][ncol] == 0
         - If nrow,ncol is destination → return dist + 1
         - If dist + 1 < distance[nrow][ncol]:
             - Update distance[nrow][ncol] = dist + 1
             - Push {dist+1, {nrow, ncol}} into queue

4. If queue empties without reaching destination → return -1.

⚠️ Assumptions:
- Grid is square (n x n).
- 0 ≤ n ≤ 1000 (or as per constraints).

🕒 Time Complexity: O(n^2)
   - Each cell visited at most once.

🧠 Space Complexity: O(n^2)
   - Distance matrix + BFS queue.
*/

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();

    int a = 0, b = 0, x = n - 1, y = n - 1;
    if (a == x && b == y && grid[a][b] == 0)
    {
        return 1;
    }
    if (grid[a][b] == 1 || grid[x][y] == 1)
    {
        return -1;
    }
    queue<pair<int, pair<int, int>>> q1;
    q1.push({1, {a, b}});
    vector<vector<int>> distance(n, vector<int>(n, 1e9));
    distance[a][b] = 0;
    int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    while (!q1.empty())
    {
        auto qel = q1.front();
        q1.pop();
        auto dist = qel.first;
        auto [row, col] = qel.second;
        for (int k = 0; k < 8; k++)
        {
            int nrow = row + delRow[k];
            int ncol = col + delCol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0)
            {
                if (x == nrow && y == ncol)
                {
                    return dist + 1;
                }
                if (dist + 1 < distance[nrow][ncol])
                {
                    distance[nrow][ncol] = dist + 1;
                    q1.push({distance[nrow][ncol], {nrow, ncol}});
                }
            }
        }
    }
    return -1;
}
int main()
{
    vector<vector<int>> vec = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    cout << shortestPathBinaryMatrix(vec);
    return 0;
}