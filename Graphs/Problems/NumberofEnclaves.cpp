// URL:https://leetcode.com/problems/number-of-enclaves/
#include <bits/stdc++.h>
using namespace std;
void bfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q1;
    q1.push({i, j});
    visited[i][j] = 1;
    int delrow[] = {0, -1, 0, 1};
    int delcol[] = {-1, 0, 1, 0};
    while (!q1.empty())
    {
        auto [row, col] = q1.front();
        q1.pop();
        for (int k = 0; k < 4; k++)
        {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !visited[nrow][ncol])
            {
                visited[nrow][ncol] = 1;
                q1.push({nrow, ncol});
            }
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int cnt = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    bfs(i, j, visited, grid);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> matrix = {
        {0},
        {1},
        {1},
        {0},
        {0}};
    cout << numEnclaves(matrix);
    return 0;
}