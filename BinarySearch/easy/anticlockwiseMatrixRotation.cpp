// URL: https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1
#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size();
    int m = mat[0].size();
    // TRANSPOSE
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // SWAP
    for (int i = 0; i < (n / 2); i++)
    {
        swap(mat[i], mat[n - i - 1]);
    }
}
int main()
{
    vector<vector<int>> mat = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}};
    rotateMatrix(mat);
    return 0;
}