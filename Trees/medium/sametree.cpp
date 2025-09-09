// URL: https://leetcode.com/problems/same-tree/description/
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
// Algorithm
// Check if both are null
// Check if one of them is null
// Check if both are not null , then check their values
// And traverse them together with recursion on both left and right side;

void dfs(Node *root1, Node *root2, int &flag)
{
    if (flag == 0)
        return;
    if (root1 == nullptr && root2 != nullptr)
    {
        flag = 0;
        return;
    }
    else if (root1 != nullptr && root2 == nullptr)
    {
        flag = 0;
        return;
    }
    else if (root1 == nullptr && root2 == nullptr)
    {
        return;
    }
    else
    {
        if (root1->data != root2->data)
        {
            flag = 0;
            return;
        }
    }
    dfs(root1->left, root2->left, flag);
    dfs(root1->right, root2->right, flag);
}
bool isSameTree(Node *p, Node *q)
{
    int flag = 1;
    dfs(p, q, flag);
    return flag != 0;
}
// same code better
bool isSameTree(Node *p, Node *q)
{
    if (!p && !q)
        return true; // both are nullptr
    if (!p || !q)
        return false; // one is nullptr, other is not
    if (p->data != q->data)
        return false; // values differ

    // recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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

    return 0;
}