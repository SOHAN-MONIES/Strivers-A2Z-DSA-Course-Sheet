// URL:https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    int N = adj.size();
    vector<int> distance(N, -1);
    distance[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    while (!q.empty())
    {
        int element = q.front().first;
        int prevDistance = q.front().second;
        q.pop();
        for (auto node : adj[element])
        {
            int newDistance = prevDistance + 1;
            if (distance[node] == -1 || newDistance < distance[node])
            {
                distance[node] = newDistance;
                q.push({node, distance[node]});
            }
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