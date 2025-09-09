// https://leetcode.com/problems/diameter-of-binary-tree/description/
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
int maxDepth(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = maxDepth(root->left, ans);
    int rh = maxDepth(root->right, ans);
    ans = max(ans, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(Node *root)
{
    int ans = 0;
    maxDepth(root, ans);
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

    return 0;
}