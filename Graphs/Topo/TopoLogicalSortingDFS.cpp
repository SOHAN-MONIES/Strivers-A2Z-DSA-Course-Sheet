// URL:https://www.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>
using namespace std;

void dfs(int element, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
{
    vis[element] = 1;
    for (auto node : adj[element])
    {
        if (!vis[node])
        {
            dfs(node, vis, st, adj);
        }
    }
    st.push(element);
}

vector<int> topoSort(int V, vector<vector<int>> &edges)
{
    vector<int> res;
    vector<int> vis(V, 0);
    vector<vector<int>> adj(V);
    stack<int> st;
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    for (int i = 0; i < V; i++)
    {
        dfs(i, vis, st, adj);
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

int main()
{

    return 0;
}