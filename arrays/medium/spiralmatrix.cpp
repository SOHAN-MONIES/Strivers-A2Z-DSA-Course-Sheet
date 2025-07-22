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
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int left = 0, top = 0, right = cols - 1, bottom = rows - 1;
    while (left <= right && top <= bottom) // left and right can be equal hence equal to
    {
        // → Traverse top row
        for (int i = left; i <= right; i++)
        {
            res.push_back(matrix[top][i]);
        }
        top++;
        // ↓ Traverse right column
        for (int i = top; i <= bottom; i++)
        {
            res.push_back(matrix[i][right]);
        }
        right--;
        // ← Traverse bottom row
        if (top <= bottom) // in a single array left direction elements will be printed ,if there  are multiple rows bottom will never be lesser than top
        {
            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        // ↑ Traverse left column
        if (left <= right) // in a single array top direction elements will be printed again , ,if there are multiple columns, right will be less right
        {
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
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
    spiralOrder(vec);
    return 0;
}