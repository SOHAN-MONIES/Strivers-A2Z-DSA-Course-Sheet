// URL:https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;

// Using two functions as disconnected graphs are available in the question
// if(parent!=node) then it is cycle
// if not understood then check using parent child tree and see if node and parent are same then it not type of cycle option , if equal then it is parent

bool isDetect(int src, vector<vector<int>> &adj, vector<int> &visited)
{
    visited[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
        int element = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto node : adj[element])
        {
            if (!visited[node])
            {
                visited[node] = 1;
                q.push({node, element});
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

    vector<vector<int>> adj(V);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(V, 0);
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            if (isDetect(i, adj, visited))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> edges = {{0, 1},
                                 {1, 2},
                                 {0, 2}};
    cout << isCycle(3, edges);
    return 0;
}