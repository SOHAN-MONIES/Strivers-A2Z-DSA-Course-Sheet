#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
vector<int> topView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    queue<pair<Node *, int>> q;
    map<int, int> mpp; // vertical axis -> value

    q.push({root, 0});

    while (!q.empty())
    {
        auto [node, vaxis] = q.front();
        q.pop();

        if (mpp.find(vaxis) == mpp.end())
            mpp[vaxis] = node->data;

        if (node->left)
            q.push({node->left, vaxis - 1});
        if (node->right)
            q.push({node->right, vaxis + 1});
    }

    for (auto &it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    vector<int> ans = topView(root);
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    return 0;
}