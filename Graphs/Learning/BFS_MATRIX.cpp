#include <bits/stdc++.h>
using namespace std;



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
