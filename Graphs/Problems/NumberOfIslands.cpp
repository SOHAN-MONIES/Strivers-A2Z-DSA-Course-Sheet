// URL: https://leetcode.com/problems/number-of-islands/
#include <bits/stdc++.h>
using namespace std;
void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
{
    visited[row][col] = 1;
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    q.push({row, col});
    while (!q.empty())
    {
        int qrow = q.front().first;
        int qcol = q.front().second;
        q.pop();
        // UPPER
        if (qrow != 0 && grid[qrow - 1][qcol] == '1' && visited[qrow - 1][qcol] == 0)
        {
            q.push({qrow - 1, qcol});
            visited[qrow - 1][qcol] = 1;
        }
        // LOWER
        if (qrow != n - 1 && grid[qrow + 1][qcol] == '1' && visited[qrow + 1][qcol] == 0)
        {
            q.push({qrow + 1, qcol});
            visited[qrow + 1][qcol] = 1;
        }
        // LEFT
        if (qcol != 0 && grid[qrow][qcol - 1] == '1' && visited[qrow ][qcol-1] == 0)
        {
            q.push({qrow, qcol - 1});
            visited[qrow][qcol - 1] = 1;
        }
        // RIGHT
        if (qcol != m - 1 && grid[qrow][qcol + 1] == '1' && visited[qrow ][qcol+1] == 0)
        {
            q.push({qrow, qcol + 1});
            visited[qrow][qcol + 1] = 1;
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int cnt = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                bfs(i, j, visited, grid);
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << numIslands(grid);
    return 0;
}