// URL:
#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto row : times)
    {
        int u = row[0];
        int v = row[1];
        int w = row[2];
        adj[u].push_back({v, w});
    }
    vector<int> distance(n + 1, 1e9);
    distance[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    while (!pq.empty())
    {
        auto [dist, element] = pq.top();
        pq.pop();
        for (auto it : adj[element])
        {
            auto [node, wt] = it;
            if (dist + wt < distance[node])
            {
                distance[node] = dist + wt;
                pq.push({distance[node], node});
            }
        }
    }
    for (int i = 1; i < distance.size(); i++)
    {
        if (distance[i] == 1e9)
        {
            return -1;
        }
    }
    int max_distance = *max_element(distance.begin() + 1, distance.end());
    return max_distance;
}
int main()
{
    vector<vector<int>> vec = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}};
    cout << networkDelayTime(vec, 4, 2);
    return 0;
}