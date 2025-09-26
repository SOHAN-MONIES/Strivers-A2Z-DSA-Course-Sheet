#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: BFS Traversal Using Adjacency Matrix

Problem:
- Traverse a graph level by level starting from a given node.
- Graph is represented as an adjacency matrix.

Steps:
1. Initialize:
   - visited[] = array to mark visited nodes.
   - queue q1 to store nodes in BFS order.
   - ans[] = result vector storing traversal order.
2. Push the starting node into queue and mark visited.j
3. While queue is not empty:
   - Pop front element from queue → element.
   - Add element to ans.
   - For every possible node i (0 to n-1):
       - If adj[element][i] == 1 (edge exists) AND i is not visited:
           - Push i into queue.
           - Mark i as visited.
4. Return ans (BFS traversal order).

⚠️ Assumptions:
- Graph is represented using adjacency matrix.
- Works for connected graphs; for disconnected graphs, call BFS for each unvisited node.

🕒 Time Complexity: O(V^2)
   - For each node, we check all n possible edges (adjacency matrix).

🧠 Space Complexity: O(V)
   - visited array + queue storage.
*/

vector<int> bfs(vector<vector<int>> &adj, int start)
{
    vector<int> ans;
    int n = adj.size();
    vector<int> visited(n, 0);
    queue<int> q1;
    q1.push(start);
    visited[start] = 1;

    while (!q1.empty())
    {
        int element = q1.front();
        q1.pop();
        ans.push_back(element);
        for (int i = 0; i < n; i++)
        {
            if (adj[element][i] == 1 && !visited[i])
            {
                q1.push(i);
                visited[i] = 1;
            }
        }
    }
    return ans;
}

int main()
{

    vector<vector<int>> adj = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0}};

    vector<int> res = bfs(adj, 0);

    for (auto num : res)
    {
        cout << num << " ";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> res;
    vector<int> visited(n, 0);
    queue<int> q1;

    q1.push(0);
    visited[0] = 1;

    while (!q1.empty())
    {
        int element = q1.front();
        q1.pop();
        res.push_back(element);

        // check all possible nodes
        for (int v = 0; v < n; v++)
        {
            if (adj[element][v] == 1 && visited[v] == 0)
            {
                q1.push(v);
                visited[v] = 1;
            }
        }
    }

    return res;
}

int main()
{
    // Example graph:
    // 0 -- 1
    // | \
    // 2  3
    // 2 -- 4
    vector<vector<int>> adj = {
        {0, 1, 1, 1, 0}, // node 0 connected to 1,2,3
        {1, 0, 0, 0, 0}, // node 1 connected to 0
        {1, 0, 0, 0, 1}, // node 2 connected to 0,4
        {1, 0, 0, 0, 0}, // node 3 connected to 0
        {0, 0, 1, 0, 0}  // node 4 connected to 2
    };

    vector<int> res = bfs(adj);
    for (auto num : res)
    {
        cout << num << " ";
    }

    return 0;
}
