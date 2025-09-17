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
