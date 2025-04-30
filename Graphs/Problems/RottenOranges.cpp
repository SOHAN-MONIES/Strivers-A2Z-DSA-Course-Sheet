// URL:https://leetcode.com/problems/rotting-oranges/
#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &mat)
{

    int n = mat.size();
    int m = mat[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }
        }
    }
    int tm = 0;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] != 2 && mat[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1});
                visited[nrow][ncol] = 2;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1 && visited[i][j] != 2)
            {
                return -1;
            }
        }
    }
    return tm;
}
int main()
{

    return 0;
}