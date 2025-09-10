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
/*
✅ Algorithm: Validate Binary Search Tree (BST) – Range Checking (Recursive)

Problem:
- Check if a binary tree is a valid BST.
- A valid BST must satisfy:
  - Left subtree values < root value.
  - Right subtree values > root value.
  - Both subtrees must also be valid BSTs.

Steps:
1. Use recursion with value ranges (minVal, maxVal):
   - Each node must lie strictly between minVal and maxVal.
2. Base case:
   - If node is NULL → return true (empty tree is valid).
3. Check current node:
   - If root->val ≤ minVal OR root->val ≥ maxVal → invalid, return false.
4. Recurse:
   - Left child: range = (minVal, root->val).
   - Right child: range = (root->val, maxVal).
5. Return true only if both subtrees are valid.

⚠️ Assumptions:
- Tree nodes contain integer values.
- No duplicates allowed (if duplicates allowed, we’d adjust comparison).

🕒 Time Complexity: O(n)
   - Each node is visited once.

🧠 Space Complexity: O(h)
   - h = height of tree (recursion stack).
   - O(log n) for balanced BST, O(n) for skewed tree.
*/

bool isValidBST(TreeNode *root, long long minVal, long long maxVal)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->val <= minVal || root->val >= maxVal)
        return false;
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}
bool isValidBST(TreeNode *root)
{
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);

    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    return 0;
}