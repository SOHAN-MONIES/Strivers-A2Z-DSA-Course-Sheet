// URL:https://leetcode.com/problems/search-a-2d-matrix/
#include <bits/stdc++.h>
using namespace std;

bool searchbetterMatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c = matrix[0].size();
    for (int i = 0; i < r; i++)
    {
        if (target >= matrix[i][0] && target <= matrix[i][c - 1])
        {
            return binary_search(matrix[i].begin(), matrix[i].end(), target);
        }
    }
    return false;
}

/*
   ✅ Algorithm (Binary Search in 2D Matrix as 1D):

   1. Treat the 2D matrix as a flat 1D array of size r * c.
   2. Apply binary search:
      - mid = (low + high) / 2
      - Convert 1D mid index back to 2D: matrix[mid / c][mid % c]
   3. Compare mid_value with target:
      - If equal, return true.
      - If less than target, move right (low = mid + 1).
      - If greater than target, move left (high = mid - 1).
   4. If not found, return false.

   🕒 Time Complexity: O(log (r * c)) → O(log n), where n = total elements
   🧠 Space Complexity: O(1) → No extra space used
   */
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c = matrix[0].size();
    int low = 0;
    int high = r * c - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int mid_value = matrix[mid / c][mid % c]; // because the hypothetical value of first element of a row is always a multiple of col
        if (mid_value == target)
        {
            return true;
        }
        else if (mid_value < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}