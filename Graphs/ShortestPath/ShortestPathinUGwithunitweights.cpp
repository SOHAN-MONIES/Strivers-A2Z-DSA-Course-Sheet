// URL:https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    // code here
    int V = adj.size();
    vector<int> distance(V, 1e9);
    queue<pair<int, int>> q1;
    q1.push({src, 0});
    while (!q1.empty())
    {
        auto [element, w] = q1.front();
        q1.pop();
        for (auto node : adj[element])
        {
            if (distance[node] > w + 1)
            {
                distance[node] = distance[w] + 1;
                q1.push({node, distance[node]});
            }
        }
    }
    for (int i = 0; i < distance.size(); i++)
    {
        if (distance[i] == 1e9)
        {
            distance[i] = -1;
        }
    }
    return distance;
}

int main()
{
    vector<std::vector<int>> adj = {
        {1, 3},
        {0, 2},
        {1, 6},
        {0, 4},
        {3, 5},
        {4, 6},
        {2, 5, 7, 8},
        {6, 8},
        {7, 6}};
    vector<int> res = shortestPath(adj, 0);
    for (auto dist : res)
    {
        cout << dist << " ";
    }

    return 0;
}