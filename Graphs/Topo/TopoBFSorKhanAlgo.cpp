// URL:https://www.geeksforgeeks.org/problems/topological-sort/2
#include <bits/stdc++.h>
using namespace std;
// this is solved using modified BSF ALGO
vector<int> topoSort(int V, vector<vector<int>> &edges)
{
    // code here
    vector<int> res;
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    // Convert edges to adj
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    // Find indegree for each
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
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        res.push_back(element);
        for (auto node : adj[element])
        {
            indegree[node]--;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
    }

    return res;
}
int main()
{

    return 0;
}