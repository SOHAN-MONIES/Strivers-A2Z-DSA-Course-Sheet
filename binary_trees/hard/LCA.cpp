// URL: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;
// 1. If the current node is `null`, return `null`.
// 2. If the current node is equal to `p` or `q`, return the current node.
// 3. Recursively search for `p` and `q` in the left subtree.
// 4. Recursively search for `p` and `q` in the right subtree.
// 5. If both left and right recursive calls return non-null:
//    - The current node is the **Lowest Common Ancestor**, return it.
// 6. If only one of the recursive calls returns non-null:
//    - Return that non-null node (it could be `p`, `q`, or their ancestor).
// 7. If both return null, return `null

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || p == root || q == root)
    {
        return root;
    }
    TreeNode *leftNode = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightNode = lowestCommonAncestor(root->right, p, q);
    if (leftNode == nullptr)
    {
        return rightNode;
    }
    else if (rightNode == nullptr)
    {
        return leftNode;
    }
    else if (leftNode != nullptr && rightNode != nullptr)
    {
        return root;
    }
    return root;
}

int main()
{

    return 0;
}