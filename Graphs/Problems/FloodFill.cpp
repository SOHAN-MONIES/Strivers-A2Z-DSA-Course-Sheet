// URL:https://leetcode.com/problems/flood-fill/description/
#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, int org, int color, vector<vector<int>> &visited, vector<vector<int>> &image)
{
    int n = image.size();
    int m = image[0].size();
    if (row < 0 || col < 0 || row >= n || col >= m || visited[row][col] || image[row][col] != org)
        return;

    visited[row][col] = 1;
    image[row][col] = color;

    dfs(row + 1, col, org, color, visited, image);
    dfs(row - 1, col, org, color, visited, image);
    dfs(row, col + 1, org, color, visited, image);
    dfs(row, col - 1, org, color, visited, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    int org = image[sr][sc];
    vector<vector<int>> visited(n, vector<int>(m, 0));
    if (org != color)
        dfs(sr, sc, org, color, visited, image);
    return image;
}

int main()
{

    return 0;
}