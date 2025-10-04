// URL:
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Cheapest Flights Within K Stops (Modified BFS / Bellman-Ford style)

Problem:
- Given a weighted directed graph (flights) with n cities numbered 0 to n-1.
- Find the cheapest price from src to dst with at most k stops.
- If no such route exists, return -1.

Steps:
1. Build adjacency list:
   - adj[u] = vector of pairs {v, w} representing flights from u → v with cost w.

2. Initialize:
   - distance vector of size n with 1e9 (infinity), distance[src] = 0.
   - BFS queue storing {stopsTaken, {currentNode, currentCost}}.

3. BFS / Relaxation:
   - While queue is not empty:
       - Pop front element {stops, {node, dist}}.
       - If stops > k → skip (cannot exceed k stops).
       - For each neighbor {nextNode, wt} of node:
           - If dist + wt < distance[nextNode] && stops <= k:
               - Update distance[nextNode] = dist + wt
               - Push {stops+1, {nextNode, distance[nextNode]}} into queue.

4. Return:
   - If distance[dst] == 1e9 → return -1
   - Else → return distance[dst]

⚠️ Assumptions:
- Graph can have cycles.
- Maximum stops allowed = k.

🕒 Time Complexity: O(E * K)
   - E = number of edges, each edge can be relaxed up to k times.

🧠 Space Complexity: O(n + E)
   - Adjacency list + distance array + BFS queue.
*/
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto flight : flights)
    {
        int u = flight[0];
        int v = flight[1];
        int w = flight[2];
        adj[u].push_back({v, w});
    }
    vector<int> distance(n, 1e9);
    distance[src] = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    while (!q.empty())
    {
        auto qel = q.front();
        auto stops = qel.first;
        auto [element, dist] = qel.second;
        q.pop();
        if (stops > k)
            continue;
        for (auto it : adj[element])
        {
            auto [node, wt] = it;
            if (dist + wt < distance[node] && stops <= k)
            {
                distance[node] = dist + wt;
                q.push({stops + 1, {node, distance[node]}});
            }
        }
    }
    return (distance[dst] == 1e9) ? -1 : distance[dst];
}
int main()
{

    return 0;
}