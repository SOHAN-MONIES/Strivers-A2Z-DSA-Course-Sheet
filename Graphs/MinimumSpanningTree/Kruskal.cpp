// URL:
#include <bits/stdc++.h>
using namespace std;
// User function Template for C++

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<tuple<int, int, int>> redges;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            redges.push_back({wt, u, v});
        }
        DisjointSet ds(V);
        sort(redges.begin(), redges.end());
        int mstWt = 0;
        for (auto it : redges)
        {
            auto [wt, u, v] = it;
            if (ds.findUParent(u) != ds.findUParent(v))
            {
                mstWt += wt;
                ds.unionByRank(u, v);
            }
        }
        return mstWt;
    }
};

int main()
{

    return 0;
}