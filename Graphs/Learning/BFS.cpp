// URL: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include <bits/stdc++.h>
using namespace std;

/*
✅ Algorithm: Breadth-First Search (BFS) Traversal of Graph

Problem:
- Traverse a graph level by level starting from a given node.
- Graph is represented as an adjacency list.

Steps:
1. Initialize:
   - visited[] = array to mark visited nodes.
   - queue q1 to store nodes in BFS order.
   - res[] = result vector storing traversal order.
2. Push the starting node into queue and mark visited.
3. While queue is not empty:
   - Pop front element from queue → element.
   - Add it to result.
   - For every neighbor of element:
       - If not visited:
           - Push neighbor into queue.
           - Mark neighbor as visited.
4. Return res (BFS traversal order).

⚠️ Assumptions:
- Graph is represented using adjacency list.
- Works for connected graphs; for disconnected graphs, call BFS for each unvisited node.

🕒 Time Complexity: O(V + E)
   - Each vertex is visited once, and each edge is considered once.

🧠 Space Complexity: O(V)
   - visited array + queue storage.
*/

vector<int> bfs(vector<vector<int>> &adj, int start)
{
    vector<int> res;
    vector<int> visited(adj.size(), 0);
    queue<int> q1;
    q1.push(start);
    visited[start] = 1;

    while (!q1.empty())
    {
        int element = q1.front();
        q1.pop();
        res.push_back(element);

        for (auto node : adj[element])
        {
            if (visited[node] == 0)
            {
                q1.push(node);
                visited[node] = 1;
            }
        }
    }

    return res;
}

int main()
{

    vector<vector<int>> adj = {
        {1, 2},       // 0 -> 1, 2
        {0, 3, 4, 5}, // 1 -> 0, 3, 4, 5
        {0},          // 2 -> 0
        {1},          // 3 -> 1
        {1},          // 4 -> 1
        {1, 6},       // 5 -> 1, 6
        {5}           // 6 -> 5
    };

    vector<int> res = bfs(adj, 0);
    for (auto num : res)
    {
        cout << num << " ";
    }

    return 0;
}