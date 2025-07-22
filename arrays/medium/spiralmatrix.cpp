// URL:https://leetcode.com/problems/spiral-matrix/
#include <bits/stdc++.h>
using namespace std;

/*
 ✅ Algorithm (Spiral Order Traversal of Matrix):

 1. Initialize four pointers:
    - top = 0, bottom = rows - 1
    - left = 0, right = cols - 1

 2. While (left <= right && top <= bottom):
    a. Traverse top row → from left to right.
    b. Traverse right column ↓ from top+1 to bottom.
    c. If top <= bottom, traverse bottom row ← from right-1 to left.
    d. If left <= right, traverse left column ↑ from bottom-1 to top+1.

 3. After each step, shrink the boundary (top++, right--, bottom--, left++)

 🕒 Time Complexity: O(m * n)
 - Each element is visited exactly once.

 🧠 Space Complexity: O(1) (excluding result array)
 - Only uses variables for boundaries.
 */
vector<int> spirallyTraverse(vector<vector<int>> &mat)
{
    // code here
    vector<int> res;
    int rows = mat.size();
    int cols = mat[0].size();
    int left = 0, top = 0, right = cols - 1, bottom = rows - 1;
    while (left <= right && top <= bottom)
    {
        // PRINTING TOP ROW
        for (int i = left; i <= right; i++)
        {
            res.push_back(mat[top][i]);
        }
        top++;
        // PRINTING RIGHT COL  top->bottom , right is constant
        for (int i = top; i <= bottom; i++)
        {
            res.push_back(mat[i][right]);
        }
        right--;
        // PRINTING BOTTOM ROW bottom is constant,right to left
        if (top <= bottom)
        { // single row array , will result in printing of bottom row without this condition
            for (int i = right; i >= left; i--)
            {
                res.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        // PRINTING LEFT COLUMN bottom to top, left is constant
        if (left <= right)
        { // single col array , will result in printing of left column without this condition
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> vec = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    spirallyTraverse(vec);
    return 0;
}