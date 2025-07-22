// URL:https://leetcode.com/problems/rotate-image/
#include <bits/stdc++.h>
using namespace std;
/*
   ✅ Algorithm to Rotate a Square Matrix 90° Clockwise (In-Place):

   1. **Transpose the matrix**:
      - Convert rows to columns.
      - Swap elements across the diagonal (matrix[i][j] with matrix[j][i] where i < j).

   2. **Reverse each row**:
      - After transposing, reversing each row gives the rotated matrix.

   Example:
       Before:
       1 2 3
       4 5 6
       7 8 9

       After Transpose:
       1 4 7
       2 5 8
       3 6 9

       After Row Reversal (Final Result):
       7 4 1
       8 5 2
       9 6 3

   🕒 Time Complexity: O(n²)
   - Transposing + reversing rows both touch all elements once.

   🧠 Space Complexity: O(1)
   - In-place, no extra matrix used.
   */

void rotate(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // TRANSPOSE
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) // You can skip if checking if u start j=i+1
        {
            if (i >= j) // No need of swapping diagonal elements and no need of swapping again
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    // REVERSE EVERY ARRAY OF MATRIX
    for (int i = 0; i < rows; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    rotate(matrix);

    return 0;
}