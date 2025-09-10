
// URL:https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Insert into a Binary Search Tree (BST) – Iterative

Problem:
- Insert a new value into a Binary Search Tree while maintaining BST properties.

Steps:
1. If root is NULL:
   - Create a new node with value = val and return it (tree was empty).
2. Initialize a pointer curr = root.
3. Traverse the tree:
   - If val > curr->val:
       - Move to right child.
       - If right child is NULL → insert new node there and break.
   - If val < curr->val:
       - Move to left child.
       - If left child is NULL → insert new node there and break.
4. Return the root of the modified BST.

⚠️ Assumptions:
- Standard BST property holds: left < root < right.
- No duplicate values in the BST (if duplicates exist, we usually insert into right subtree).

🕒 Time Complexity: O(h)
   - h = height of tree → O(log n) for balanced BST, O(n) for skewed tree.

🧠 Space Complexity: O(1)
   - Iterative approach, no recursion stack used.
*/
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
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->val < val)
        {
            if (curr->right != nullptr)
                curr = curr->right;
            else
            {
                curr->right = new TreeNode(val);
                break;
            }
        }
        if (curr->val > val)
        {
            if (curr->left != nullptr)
                curr = curr->left;
            else
            {
                curr->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
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

    return 0;
}
