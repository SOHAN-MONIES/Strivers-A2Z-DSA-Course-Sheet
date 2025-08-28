#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root) // Calculate the depth of the tree
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
bool isBalanced(TreeNode *root) // Check if the tree is balanced
{
    return maxDepth(root) != -1; // Return true if balanced, false if unbalanced
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);
    root->right->right->right->right = new TreeNode(11);
    cout << isBalanced(root);
    return 0;
}