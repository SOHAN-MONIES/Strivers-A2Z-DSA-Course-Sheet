// URL: https://leetcode.com/problems/number-of-provinces/description/
#include <bits/stdc++.h>
using namespace std;

void dfs(int element, vector<int> &visited, vector<vector<int>> &adj)
{
    visited[element] = 1;
    for (int node : adj[element])
    {
        if (!visited[node])
        {
            dfs(node, visited, adj);
        }
    }
}

int numProvinces(vector<vector<int>> &isConnected)
{
    int cnt = 0;
    vector<int> visited(isConnected.size() + 1, 0);
    vector<vector<int>> adj(isConnected.size() + 1);
    for (int i = 0; i < isConnected.size(); i++)
    {
        for (int j = 0; j < isConnected[i].size(); j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adj[i + 1].push_back(j + 1);
                adj[j + 1].push_back(i + 1);
            }
        }
    }

    for (int i = 1; i < visited.size(); i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, visited, adj);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> adj = {{1, 0, 1},
                               {0, 1, 0},
                               {1, 0, 1}};
    cout << numProvinces(adj);
    return 0;
}