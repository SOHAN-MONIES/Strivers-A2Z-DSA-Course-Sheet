// URL: https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> v1(V);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        v1[u].push_back(v);
        v1[v].push_back(u);
    }
    return v1;
}

int main()
{
    vector<pair<int, int>> edges;
    edges = {{0, 3}, {0, 2}, {2, 1}};
    int V = 4;
    vector<vector<int>> v1 = printGraph(V, edges);
    for (int i = 0; i < v1.size(); i++)
    {
        cout << i << ":";
        for (auto node : v1[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}