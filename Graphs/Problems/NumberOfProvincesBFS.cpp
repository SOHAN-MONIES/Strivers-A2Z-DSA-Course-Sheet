#include <bits/stdc++.h>
using namespace std;

// BFS directly on adjacency matrix
void bfs(int start, vector<int> &visited, vector<vector<int>> &isConnected)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[node][j] == 1 && !visited[j])
            {
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

int numProvinces(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> visited(n, 0);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(i, visited, isConnected);
            count++;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> isConnected = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};

    cout << "Number of Provinces: " << numProvinces(isConnected) << endl; // Output: 2
}
