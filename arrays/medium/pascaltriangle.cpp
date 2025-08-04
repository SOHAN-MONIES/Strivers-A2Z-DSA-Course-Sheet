// URL: 
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangleCreation(int n)
{
    vector<vector<int>> res;
    for (int i = 0; i < n;i++){
        vector<int> levels(i + 1, 1);
        for (int j = 1; j < i;j++){
            levels[j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        res.push_back(levels);
    }

        return res;
}
int main() {
    vector<vector<int>> res = pascalTriangleCreation(5);
    for (auto row : res)
    {
        for (auto element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}