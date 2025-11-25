// URL:https://leetcode.com/problems/minimum-falling-path-sum/
#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int> > &matrix) {
    if (i == matrix.size() - 1) {
        return matrix[i][j];
    }
    int left = 1e9;

    int right = 1e9;

    int down = matrix[i][j] + f(i + 1, j, matrix);

    if (j < matrix.size() - 1) {
        right = matrix[i][j] + f(i + 1, j + 1, matrix);
    }
    if (j != 0) {
        left = matrix[i][j] + f(i + 1, j - 1, matrix);
    }
    return min(down, min(right, left));
}

int minFallingPathSum(vector<vector<int> > &matrix) {
    int n = matrix.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int fans = f(0, i, matrix);
        ans = min(ans, fans);
    }
    return ans;
}

int main() {
    vector<vector<int> > matrix = {
        {-19, 57},
        {-40, -5},

    };
    cout << minFallingPathSum(matrix);
    return 0;
}
