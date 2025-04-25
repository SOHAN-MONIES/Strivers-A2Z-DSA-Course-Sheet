// URL: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj)
{
    vector<int> res;
    vector<int> visited(adj.size(), 0);
    queue<int> q1;
    q1.push(0);
    visited[0] = 1;

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
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> res = bfs(adj);
    for (auto num : res)
    {
        cout << num << " ";
    }

    return 0;
}