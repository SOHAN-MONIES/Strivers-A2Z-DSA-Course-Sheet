// URL:
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 0);
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
    void unionSize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (size[ulp_v] < size[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u]++;
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionSize(1, 2);
    ds.unionSize(2, 3);
    ds.unionSize(4, 5);
    ds.unionSize(6, 7);
    ds.unionSize(5, 6);

    ds.unionSize(3, 7);
    if (ds.findUParent(3) == ds.findUParent(7))
    {
        cout << "Same";
    }
    else
    {
        cout << "Not Same";
    }
    return 0;
}