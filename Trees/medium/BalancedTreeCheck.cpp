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

int maxDepth(Node *root) // Calculate the depth of the tree
{
    if (root == NULL) // Base case: null node has depth 0
    {
        return 0;
    }

    int lh = maxDepth(root->left);  // Get depth of the left subtree
    int rh = maxDepth(root->right); // Get depth of the right subtree

    if (lh == -1 || rh == -1) // Early exit if left or right subtree is unbalanced
        return -1;

    if (abs(lh - rh) > 1) // If difference in heights is more than 1, tree is unbalanced
        return -1;        // Return -1 to indicate unbalanced tree

    return 1 + max(lh, rh); // Return the depth of the tree rooted at this node
}
bool isBalanced(Node *root) // Check if the tree is balanced
{
    return maxDepth(root) != -1; // Return true if balanced, false if unbalanced
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
    root->right->right->right->right = new Node(11);
    cout << isBalanced(root);
    return 0;
}