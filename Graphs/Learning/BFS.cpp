// URL: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include <bits/stdc++.h>
using namespace std;

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