#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj, int start)
{
    int n = adj.size(); // number of vertices
    vector<int> res;
    vector<int> visited(n, 0);
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);

        // check all possible vertices
        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                q.push(v);
                visited[v] = 1;
            }
        }
    }

    return res;
}

int main()
{
    int n = 5;
    vector<vector<int>> adj(n, vector<int>(n, 0));

    // Sample graph
    // 0-1, 0-2, 0-3, 2-4
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[0][3] = adj[3][0] = 1;
    adj[2][4] = adj[4][2] = 1;

    vector<int> res = bfs(adj, 0);

    for (auto num : res)
    {
        cout << num << " ";
    }

    return 0;
}
