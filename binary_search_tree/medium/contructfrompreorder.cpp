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
✅ Algorithm: Construct BST from Preorder Traversal (Recursive with Upper Bound)

Problem:
- Given the preorder traversal of a BST, construct and return the BST.

Steps:
1. Maintain an index `i` to track the current root in preorder.
2. Recursive function build(preorder, i, maxVal):
   - Base case:
     - If i == preorder.size() → no more nodes, return NULL.
     - If preorder[i] > maxVal → current value cannot fit here, return NULL.
   - Create a new node with preorder[i].
   - Increment i.
   - Recursively build the left subtree with upper bound = root->val.
   - Recursively build the right subtree with upper bound = maxVal.
   - Return root.
3. Start recursion with:
   - i = 0
   - maxVal = INT_MAX (no limit for root).
4. Return the constructed root.

⚠️ Assumptions:
- Input is a valid preorder traversal of a BST.
- Tree node values fit within int range.

🕒 Time Complexity: O(n)
   - Each element is inserted exactly once.

🧠 Space Complexity: O(h)
   - h = height of BST (recursion stack).
   - O(log n) for balanced tree, O(n) for skewed tree.
*/

TreeNode *build(vector<int> &preorder, int &i, int maxVal)
{
    if (i == preorder.size() || preorder[i] > maxVal)
        return nullptr;

    TreeNode *root = new TreeNode(preorder[i]);
    ++i;

    root->left = build(preorder, i, root->val);
    root->right = build(preorder, i, maxVal);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return build(preorder, i, INT_MAX);
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