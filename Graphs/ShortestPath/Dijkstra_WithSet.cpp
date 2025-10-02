#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
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
    set<pair<int, int>> s;
    s.insert({0, src});

    while (!s.empty())
    {
        auto it = *s.begin();
        s.erase(s.begin());

        int dist = it.first;
        int element = it.second;

        for (auto edge : adj[element])
        {
            int adjNode = edge.first;
            int wt = edge.second;

            if (dist + wt < distance[adjNode])
            {

                if (distance[adjNode] != 1e9)
                    s.erase({distance[adjNode], adjNode});

                distance[adjNode] = dist + wt;
                s.insert({distance[adjNode], adjNode});
            }
        }
    }

    return distance;
}
