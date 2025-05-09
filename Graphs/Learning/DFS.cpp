// URL:https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include <bits/stdc++.h>
using namespace std;

void dfs(int element, vector<vector<int>> &adj, vector<int> &res, vector<int> &visited)
{
    visited[element] = 1;
    res.push_back(element);
    for (int node : adj[element])
    {
        if (!visited[node])
        {
            dfs(node, adj, res, visited);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj)
{
    vector<int> visited(adj.size(), 0);
    vector<int> res;
    dfs(0, adj, res, visited);
    return res;
}
int main()
{
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> res = dfs(adj);
    for (auto num : res)
    {
        cout << num << " ";
    }
    return 0;
}