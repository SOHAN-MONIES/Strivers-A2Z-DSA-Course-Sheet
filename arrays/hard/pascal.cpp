// URL:https://leetcode.com/problems/pascals-triangle/description/
#include <bits/stdc++.h>
using namespace std;
/*
Algorithm: Generate Pascal's Triangle

1. Initialize an empty result vector "res".

2. Loop i from 0 to numRows-1:
   - Create a vector "level" of size (i+1), initialized with 1.
   - For each j from 1 to i-1:
       - level[j] = res[i-1][j-1] + res[i-1][j]
       - (Each element is sum of the two numbers above it in Pascal’s Triangle)
   - Push "level" into res.

3. Return res.

Example for numRows = 5:
[
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
]

Time Complexity: O(numRows^2)
   - For each row, we fill up to i elements.
   - Total elements = 1 + 2 + … + numRows = O(numRows^2).

Space Complexity: O(numRows^2)
   - Output requires storing all rows of Pascal’s triangle.
*/
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> level(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            level[j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        res.push_back(level);
    }

    return res;
}
int main()
{

    return 0;
}