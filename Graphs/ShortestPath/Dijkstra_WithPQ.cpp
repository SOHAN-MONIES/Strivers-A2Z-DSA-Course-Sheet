// URL:https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    vector<vector<pair<int, int>>> adj(V);
    for (auto row : edges)
    {
        int u = row[0];
        int v = row[1];
        int wt = row[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<int> distance(V, 1e9);
    distance[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto [dist, element] = pq.top();
        pq.pop();
        for (auto it : adj[element])
        {
            auto node = it.first;
            auto w = it.second;
            int prevDistance = distance[node];
            if (dist + w < prevDistance)
            {
                distance[node] = dist + w;
                pq.push({distance[node], node});
            }
        }
    }
    return distance;
}

int main()
{

    return 0;
}