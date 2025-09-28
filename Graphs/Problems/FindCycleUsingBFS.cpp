// URL:https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;

/*
✅ Algorithm: Cycle Detection in Undirected Graph (BFS)

Problem:
- Given V vertices and an edge list, check if the undirected graph contains a cycle.

Steps:
1. Build adjacency list from edges.
   - For each edge (u, v):
       - Add v to adj[u] and u to adj[v].

2. Initialize a visited array of size V with 0 (unvisited).

3. For every unvisited node, run BFS:
   - Push {node, parent} into queue (parent = -1 for root).
   - Mark node as visited.

4. BFS traversal:
   - Pop {element, parent} from queue.
   - For every neighbor of element:
       - If not visited:
           - Mark visited and push {neighbor, element}.
       - Else if visited and neighbor != parent:
           - Cycle found → return true.

5. If BFS finishes for all components without detecting a cycle → return false.

⚠️ Assumptions:
- Graph is undirected.
- Input edges are given as pairs (u, v).
- Graph can be disconnected → hence we loop through all nodes.

🕒 Time Complexity: O(V + E)
   - Each vertex and edge is processed once.

🧠 Space Complexity: O(V + E)
   - Adjacency list + visited array + queue.
*/
bool bfs(vector<vector<int>> &adj, vector<int> &visited, int start)
{
    queue<pair<int, int>> q1;
    q1.push({start, -1});

    visited[start] = 1;
    while (!q1.empty())
    {
        auto [element, parent] = q1.front();
        q1.pop();
        for (auto node : adj[element])
        {
            if (!visited[node])
            {
                visited[node] = 1;
                q1.push({node, element});
            }
            else
            {
                if (parent != node)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> &edges)
{
    // Code here
    vector<vector<int>> adj(V);
    for (auto row : edges)
    {
        int x = row[0];
        int y = row[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {

        if (!visited[i])
        {
            if (bfs(adj, visited, i))
            {
                return true;
            }
        }
    }

    return false;
}
int main()
{

    return 0;
}