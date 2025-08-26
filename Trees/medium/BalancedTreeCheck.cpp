// URL: https://leetcode.com/problems/balanced-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(TreeNode *root) // Check if the tree is balanced
{
    return maxDepth(root) != -1; // Return true if balanced, false if unbalanced
}

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

int main()
{

    return 0;
}