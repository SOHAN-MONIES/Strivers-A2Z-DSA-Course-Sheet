#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(V + 1);

    for (auto &e : edges)
    {
        int u = e.first;
        int v = e.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

int main()
{
    // Example: Graph with V = 7 (0..6)
    int V = 6;
    vector<pair<int, int>> edges = {
        {1, 2}, {2, 3}, {2, 4}, {2, 5}, {1, 6}};

    vector<vector<int>> adj = printGraph(V, edges);

    for (int i = 1; i <= V; i++)
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