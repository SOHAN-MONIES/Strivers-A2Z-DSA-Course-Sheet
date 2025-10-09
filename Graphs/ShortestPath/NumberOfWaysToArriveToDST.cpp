// URL:https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Number of Ways to Arrive at Destination
(Using Dijkstra’s Algorithm + Path Counting)

🧩 Problem:
- Given an undirected weighted graph with `n` nodes (0 to n-1) and roads[][] = {u, v, time}.
- Find the number of different shortest paths from node 0 to node n-1.
- Since the answer can be large, return it modulo (1e9 + 7).

-------------------------------------------------
⚙️ Steps:

1. Build Adjacency List:
   - For each road [u, v, time]:
       adj[u].push_back({v, time})
       adj[v].push_back({u, time})   // because the graph is undirected.

2. Initialize:
   - distance[i] = ∞ for all i
   - ways[i] = 0 for all i
   - distance[0] = 0  (source)
   - ways[0] = 1      (one way to reach the start node)
   - Use a min-heap (priority_queue with greater<>) storing {dist, node}.

3. Dijkstra’s Algorithm:
   - While the priority queue is not empty:
       - Pop (dist, node)
       - For each neighbor (adjNode, wt):
            case 1️⃣: Found a *shorter* path
                if (dist + wt < distance[adjNode]):
                    distance[adjNode] = dist + wt
                    ways[adjNode] = ways[node]   // inherit number of ways
                    pq.push({distance[adjNode], adjNode})

            case 2️⃣: Found *another* shortest path (equal distance)
                else if (dist + wt == distance[adjNode]):
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod

4. Return:
   - ways[n - 1] → number of distinct shortest paths to destination.

-------------------------------------------------
📊 Time Complexity:
   O((E + V) * logV)
   - E = number of edges
   - V = number of vertices
   - Dijkstra’s algorithm with a min-heap.

💾 Space Complexity:
   O(V + E)
   - Adjacency list + distance[] + ways[] + priority queue.

-------------------------------------------------
🧠 Intuition:
- Use Dijkstra’s to compute shortest distances.
- Track number of ways to reach each node with shortest distance.
- Whenever a new shortest path is found → reset ways[node].
- Whenever another shortest path of same length is found → add ways.

-------------------------------------------------
🔢 Example:
n = 7
roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],
         [6,3,3],[3,5,1],[6,5,1],[2,5,1]()
*/
int countPaths(int n, vector<vector<int>> &roads)
{
    long long mod = 1000000007;
    vector<vector<pair<int, int>>> adj(n);
    for (auto road : roads)
    {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }
    vector<long long> distance(n, 1e18);
    vector<int> way(n, 0);
    way[0] = 1;
    distance[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
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
                way[node] = way[element];
            }
            else if (dist + wt == distance[node])
            {

                way[node] = (way[node] + way[element]) % mod;
            }
        }
    }
    return way[n - 1];
}
int main()
{
    vector<vector<int>> edges = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}};
    cout << countPaths(7, edges);
    return 0;
}