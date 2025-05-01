// URL:https://leetcode.com/problems/flood-fill/description/
#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int init, int color, int delRow[], int delCol[])
{
    int n = image.size();
    int m = image[0].size();
    ans[row][col] = color;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] != color && image[nrow][ncol] == init)
        {
            dfs(nrow, ncol, ans, image, init, color, delRow, delCol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int init = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(sr, sc, ans, image, init, color, delRow, delCol);
    return ans;
}

int main()
{

    return 0;
}