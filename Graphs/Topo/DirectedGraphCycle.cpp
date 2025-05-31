// URL:https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<vector<int>> &edges)
{

    // Convert edges to adj
    vector<vector<int>> adj(V);
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    // Find indegree for each
    vector<int> indegree(V);
    for (int i = 0; i < V; i++)
    {
        for (auto node : adj[i])
        {
            indegree[node]++;
        }
    }

    // Enter the elements to queue if indegree in zero
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Until the queue size is zero , reduce the indegree of adjaceny node by 1 when , indegree in zero add it to the queue
    int cnt = 0;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        cnt++;
        for (auto node : adj[element])
        {
            indegree[node]--;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
    }

    if (cnt == V)
    {
        return false;
    }
    return true;
}

int main()
{

    return 0;
}