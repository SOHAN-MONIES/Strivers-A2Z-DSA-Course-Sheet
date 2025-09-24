// URL: https://leetcode.com/problems/number-of-provinces/description/
#include <bits/stdc++.h>
using namespace std;

// DFS directly on adjacency matrix
void dfs(int node, vector<int> &visited, vector<vector<int>> &isConnected)
{
    visited[node] = 1;
    for (int j = 0; j < isConnected.size(); j++)
    {
        if (isConnected[node][j] == 1 && !visited[j])
        {
            dfs(j, visited, isConnected);
        }
    }
}

int numProvinces(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> visited(n, 0);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, isConnected);
            count++;
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> adj = {{1, 0, 1},
                               {0, 1, 0},
                               {1, 0, 1}};
    cout << numProvinces(adj);
    return 0;
}