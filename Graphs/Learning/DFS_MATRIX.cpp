#include <bits/stdc++.h>
using namespace std;

void dfs(int element, vector<vector<int>> &adj, vector<int> &res, vector<int> &visited)
{
    visited[element] = 1;
    res.push_back(element);
    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[element][i] == 1 && !visited[i])
        {
            dfs(i, adj, res, visited);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj)
{
    vector<int> visited(adj.size(), 0);
    vector<int> res;
    dfs(0, adj, res, visited);
    return res;
}

int main()
{
    vector<vector<int>> adj = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0}};

    vector<int> res = dfs(adj);

    for (auto num : res)
    {
        cout << num << " ";
    }

    return 0;
}
