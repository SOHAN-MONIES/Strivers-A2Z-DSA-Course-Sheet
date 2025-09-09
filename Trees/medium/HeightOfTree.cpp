// URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
// Level Order Solution
int maxDepthl(Node *root)
{
    int depth = 0;
    if (root == nullptr)
        return depth;
    queue<Node *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        int n = q1.size();
        for (int i = 0; i < n; i++)
        {
            Node *element = q1.front();
            q1.pop();
            if (element->left)
            {
                q1.push(element->left);
            }
            if (element->right)
            {
                q1.push(element->right);
            }
        }
        depth++;
    }
    return depth;
}

// Recursive Solution
int maxDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
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
    cout << maxDepth(root);
    return 0;
}