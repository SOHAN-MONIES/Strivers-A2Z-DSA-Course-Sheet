// URL:https://leetcode.com/problems/course-schedule/description/
#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
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
    int cnt = 0;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        cnt++;
        for (auto node : adj[element])
        {
            indegree[node]--;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
    }
    if (cnt == numCourses)
    {
        return true;
    }
    return false;
}
int main()
{

    return 0;
}