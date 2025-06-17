// URL:https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<vector<pair<int, int>>> &adj)
{
    vis[node] = 1;
    for (auto element : adj[node])
    {
        if (!vis[element.first])
        {
            dfs(element.first, st, vis, adj);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(V);
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
    }
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj);
        }
    }

    vector<int> distance(V, -1);
    distance[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;
            if (distance[v] == -1 || distance[node] + wt < distance[v])
            {
                distance[v] = distance[node] + wt;
            }
        }
    }

    return distance;
}
int main()
{
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 1}};

    vector<int> res = shortestPath(4, 2, edges);
    for (auto el : res)
    {
        cout << el << " ";
    }
}