#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(V);

    for (auto &e : edges)
    {
        int u = e.first;
        int v = e.second;

        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    return adj;
}

int main()
{
    int V = 6;
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {1, 3}, {1, 4}, {0, 5}};

    vector<vector<int>> adj = printGraph(V, edges);

    for (int i = 0; i < V; i++)
    {
        cout << i << ":";
        for (auto node : adj[i])
        {
            cout << " " << node;
        }
        cout << "\n";
    }

    return 0;
}
