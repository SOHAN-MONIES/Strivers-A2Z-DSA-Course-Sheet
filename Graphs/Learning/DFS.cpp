// URL:https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &result)
{
    visited[node] = 1;
    result.push_back(node);

    for (int node : adj[node])
    {
        if (!visited[node])
        {
            dfsHelper(node, adj, visited, result);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj)
{

    vector<int> visited(adj.size(), 0);
    vector<int> result;

    dfsHelper(0, adj, visited, result);

    return result;
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