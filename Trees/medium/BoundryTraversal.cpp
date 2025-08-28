// URL: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void addLeftNodes(Node *root, vector<int> &res)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    res.push_back(root->data);

    if (root->left)
        addLeftNodes(root->left, res);
    else
        addLeftNodes(root->right, res);
}

void addLeafNode(Node *root, vector<int> &res)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
    {
        res.push_back(root->data);
        return;
    }

    addLeafNode(root->left, res);
    addLeafNode(root->right, res);
}

void addRightNode(Node *root, vector<int> &rightBoundary)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    if (root->right)
        addRightNode(root->right, rightBoundary);
    else
        addRightNode(root->left, rightBoundary);

    rightBoundary.push_back(root->data); // Store in reverse order
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    if (root->left == nullptr && root->right == nullptr)
    {
        res.push_back(root->data);
        return res;
    }
    res.push_back(root->data); // Root node

    vector<int> rightBoundary;

    addLeftNodes(root->left, res);
    addLeafNode(root, res);
    addRightNode(root->right, rightBoundary);

    res.insert(res.end(), rightBoundary.begin(), rightBoundary.end());

    return res;
}

int main()
{

    return 0;
}