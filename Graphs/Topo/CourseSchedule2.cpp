// URL:https://leetcode.com/problems/course-schedule-ii/description/
#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for (auto edge : prerequisites)
    {
        int u = edge[0];
        int v = edge[1];
        adj[v].push_back(u);
    }

    // calculate indegree
    vector<int> indegree(numCourses);
    for (int i = 0; i < numCourses; i++)
    {
        for (auto node : adj[i])
        {
            indegree[node]++;
        }
    }

    // if indegree in zero , put the elements in queue
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // until queue is empty , if element is a neighbour reduce the indegree by one and if zero add to the queue
    vector<int> res;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        res.push_back(element);
        for (auto node : adj[element])
        {
            indegree[node]--;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
    }
    if (res.size() == numCourses)
    {
        return res;
    }
    return {};
}
int main()
{

    return 0;
}