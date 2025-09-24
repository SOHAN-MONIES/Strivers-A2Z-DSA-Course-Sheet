/*
✅ Algorithm: BFS for Number of Islands / Grid Traversal

Problem:
- Traverse a 2D grid of '1's (land) and '0's (water).
- Mark all connected land cells (up, down, left, right) as visited.

Steps:
1. Initialize:
   - visited[n][m] = 2D array of same size as grid to track visited cells.
   - queue q to store cells to visit next.
   - direction arrays:
       drow[] = {-1, 0, 1, 0}  // up, right, down, left
       dcol[] = {0, 1, 0, -1}
2. Start BFS:
   - Push starting cell (row, col) into queue.
   - Mark visited[row][col] = 1.
3. While queue is not empty:
   - Pop front cell (x, y).
   - For each direction k = 0..3:
       - Compute neighbor coordinates: delrow = x + drow[k], delcol = y + dcol[k].
       - If neighbor is in bounds, is '1', and not visited:
           - Mark visited[delrow][delcol] = 1.
           - Push neighbor into queue.
4. Continue until all reachable cells are visited.

⚠️ Assumptions:
- grid contains only '0' and '1'.
- Moves allowed only in 4 directions (up, down, left, right).

🕒 Time Complexity: O(n * m)
   - Each cell is visited at most once.

🧠 Space Complexity: O(n * m)
   - Visited array + queue storing cells.
*/
void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int delrow = x + drow[k];
            int delcol = y + dcol[k];

            if (delrow >= 0 && delcol >= 0 && delrow < n && delcol < m &&
                grid[delrow][delcol] == '1' && !visited[delrow][delcol])
            {
                visited[delrow][delcol] = 1;
                q.push({delrow, delcol});
            }
        }
    }
}
