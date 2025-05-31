// URL:https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, int parent, vector<int> &visited, vector<vector<int>> &adj)
{
    visited[src] = 1;
    for (auto node : adj[src])
    {
        if (!visited[node])
        {
            if (dfs(node, src, visited, adj))
            {
                return true;
            }
        }
        else
        {
            if (parent != node)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> &edges)
{
    // Code here
    vector<vector<int>> adj(V);
    vector<int> visited(V, 0);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, visited, adj))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    return 0;
}