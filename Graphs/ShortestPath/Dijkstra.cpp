// URL:https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    vector<vector<pair<int, int>>> adj(V);
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
    }

    vector<int> distance(V, INF);
    distance[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;

        for (auto it : adj[node])
        {
            int neighbour = it.second;
            int wt = it.first;
            if (distance[node] + wt < distance[neighbour])
            {
                distance[neighbour] = distance[node] + wt;
                pq.push({distance[neighbour], neighbour});
            }
        }
    }
    return distance;
}

int main()
{

    return 0;
}