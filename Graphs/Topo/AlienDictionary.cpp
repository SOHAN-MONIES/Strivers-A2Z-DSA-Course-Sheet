// URL:https://www.geeksforgeeks.org/problems/alien-dictionary/1
#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int N, vector<vector<int>> adj)
{
    vector<int> topoSort;
    // find indegree
    vector<int> indegree(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (auto node : adj[i])
        {
            indegree[node]++;
        }
    }
    queue<int> q1;
    // insert into queue whose indgree is zero
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q1.push(i);
        }
    }
    // decrease the indegree of neighbors by one in q
    while (!q1.empty())
    {
        int element = q1.front();
        q1.pop();
        topoSort.push_back(element);
        for (auto node : adj[element])
        {
            indegree[node]--;
            if (indegree[node] == 0)
                q1.push(node);
        }
    }

    return topoSort;
}

string findOrder(vector<string> &words)
{
    set<char> s;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].size(); j++)
        {
            s.insert(words[i][j]);
        }
    }
    int k = s.size();
    vector<vector<int>> adj(26);
    for (int i = 0; i < words.size() - 1; i++)
    {
        string s1 = words[i];
        string s2 = words[i + 1];

        int cmp = min(s1.size(), s2.size());
        for (int j = 0; j < cmp; j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
            if (j == cmp - 1 && s1.size() > cmp)
            {
                return "";
            }
        }
    }
    vector<int> res = topoSort(26, adj);
    string ans = "";
    for (int i = 0; i < res.size(); i++)
    {
        char ch = char(res[i] + 'a');
        if (s.count(ch))
        {
            ans = ans + ch;
        }
    }
    if (ans.size() != k)
        return "";
    return ans;
}

int main()
{

    return 0;
}