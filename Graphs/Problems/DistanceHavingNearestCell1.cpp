// URL:https://leetcode.com/problems/01-matrix/description/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: 01 Matrix – Nearest Distance to 0 (BFS)

Problem:
- Given a binary matrix mat of size n × m:
  - Each cell contains 0 or 1.
  - For each cell containing 1, find the distance to the nearest 0.
- Distance is measured in terms of 4-directional moves (up, down, left, right).

Steps:
1. Initialize:
   - visited[n][m] = track visited cells.
   - ans[n][m] = result matrix storing minimum distance to nearest 0.
   - Queue q1 for BFS traversal.

2. Multi-source BFS setup:
   - Traverse matrix.
   - For each cell with value 0:
       - Mark visited[i][j] = 1
       - Push (i, j) into queue
       - Distance for 0-cells remains 0.

3. BFS traversal:
   - While queue is not empty:
       - Pop (row, col).
       - Explore 4 neighbors using delrow[], delcol[].
       - If neighbor is valid, unvisited, and has value 1:
           - Mark as visited.
           - Set ans[nrow][ncol] = ans[row][col] + 1.
           - Push neighbor into queue.

4. Continue BFS until all reachable cells are processed.

5. Return ans.

⚠️ Assumptions:
- At least one 0 exists in the matrix (otherwise result would be invalid).
- Movement allowed only in 4 directions.

🕒 Time Complexity: O(n × m)
   - Each cell is pushed into queue at most once.

🧠 Space Complexity: O(n × m)
   - For visited matrix, ans matrix, and BFS queue.
*/

vector<vector<int>> updateMatrix(vector<vector<int>> &isWater)
{

    int n = isWater.size();
    int m = isWater[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    queue<pair<int, int>> q1;
    // visit elements having value of 0 and mark it as visited and ensure its pushed inside queue
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isWater[i][j] == 0)
            {
                visited[i][j] = 1;
                q1.push({i, j});
            }
        }
    }
    int delrow[] = {0, -1, 0, +1};
    int delcol[] = {-1, 0, +1, 0};
    while (!q1.empty())
    {
        auto [row, col] = q1.front();
        q1.pop();
        for (int k = 0; k < 4; k++)
        {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && isWater[nrow][ncol] == 1)
            {
                visited[nrow][ncol] = 1;
                ans[nrow][ncol] = ans[row][col] + 1;
                q1.push({nrow, ncol});
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix = {
        {0},
        {0},
        {0},
        {0}};

    vector<vector<int>> ans = updateMatrix(matrix);
    // Example: print the matrix
    for (auto row : ans)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}