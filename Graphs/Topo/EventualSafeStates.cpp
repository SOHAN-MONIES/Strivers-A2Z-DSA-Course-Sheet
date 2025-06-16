// URL:https://leetcode.com/problems/find-eventual-safe-states/submissions/1661706371/
#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<vector<int>> adjRev(V);
    vector<int> indegree(V, 0);
    vector<int> safeNodes;
    for (int i = 0; i < V; i++)
    {
        for (auto node : graph[i])
        {
            adjRev[node].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        safeNodes.push_back(element);
        for (auto node : adjRev[element])
        {
            indegree[node]--;
            if (indegree[node] == 0)
                q.push(node);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}