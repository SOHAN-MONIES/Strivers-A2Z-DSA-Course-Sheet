// URL:https://leetcode.com/problems/surrounded-regions/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Surrounded Regions (Replace 'O' with 'X')

Problem:
- Given a matrix board[n][m] with characters 'X' and 'O':
  - Replace all 'O's that are completely surrounded by 'X' with 'X'.
  - 'O's connected to the boundary (directly or indirectly) should NOT be replaced.

Steps:
1. Initialize:
   - visited[n][m] = matrix to track visited cells.

2. DFS Boundary Traversal:
   - Traverse all boundary cells (first row, last row, first column, last column).
   - If a boundary cell contains 'O', perform DFS from that cell.
   - DFS marks all connected 'O's as visited → meaning they are "safe" and cannot be flipped.

3. Convert Internal Regions:
   - After DFS, traverse the board again.
   - For every cell:
       - If board[i][j] == 'O' and not visited → flip to 'X' (since it's fully surrounded).
       - Else leave it as is.

4. Return the modified board.

⚠️ Assumptions:
- Board contains only 'X' and 'O'.
- Connectivity is 4-directional (up, down, left, right).

🕒 Time Complexity: O(n × m)
   - Each cell is visited at most once.

🧠 Space Complexity: O(n × m)
   - For the visited matrix and recursion stack (DFS).
   - Can be optimized by marking cells directly in board instead of visited[].
*/

void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == 1 || mat[i][j] == 'X')
    {
        return;
    }
    visited[i][j] = 1;
    dfs(i + 1, j, visited, mat);
    dfs(i, j - 1, visited, mat);
    dfs(i - 1, j, visited, mat);
    dfs(i, j + 1, visited, mat);
}

void solve(vector<vector<char>> &board)
{
    // code here
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && (board[i][j] == 'O'))
            {
                dfs(i, j, visited, board);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O' && !visited[i][j])
            {
                board[i][j] = 'X';
            }
        }
    }
}
int main()
{

    vector<vector<char>> grid = {
        {'X', 'X', 'O', 'O', 'X', 'X', 'O', 'O', 'O'},
        {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'O'},
        {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
        {'O', 'O', 'O', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'O', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O'},
        {'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'O'},
        {'X', 'O', 'O', 'X', 'X', 'O', 'X', 'X', 'X'}};

    for (auto row : grid)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
