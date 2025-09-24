#include <bits/stdc++.h>
using namespace std;

// DFS to mark all connected land cells
void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    int n = grid.size();
    int m = grid[0].size();

    visited[row][col] = true;

    // 4 directions: up, right, down, left
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++)
    {
        int newRow = row + drow[k];
        int newCol = col + dcol[k];

        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            grid[newRow][newCol] == '1' && !visited[newRow][newCol])
        {
            dfs(newRow, newCol, grid, visited);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                dfs(i, j, grid, visited);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << "Number of Islands: " << numIslands(grid) << endl; // Output: 3
}
