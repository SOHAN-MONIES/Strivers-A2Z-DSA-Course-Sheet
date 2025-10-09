// URL:
#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
        }
    }
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        dist[u][v] = wt;
        dist[v][u] = wt;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != 1e9 && dist[j][k] != 1e9)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int ans = -1;
    int maxCount = n + 1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] <= distanceThreshold && dist[i][j] != 0)
            {
                cnt++;
            }
        }
        if (cnt <= maxCount)
        {
            ans = max(ans, i);
            maxCount = min(cnt, maxCount);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 8},
        {1, 2, 3},
        {1, 4, 2},
        {2, 3, 1},
        {3, 4, 1}};
    cout << findTheCity(5, edges, 2);
    return 0;
}