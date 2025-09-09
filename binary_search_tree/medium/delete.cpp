#include <bits/stdc++.h>
using namespace std;
/*
✅ Algorithm: Delete Node in a Binary Search Tree (BST)

Problem:
- Delete a node with a given key from a BST while maintaining BST properties.

Steps:
1. Helper Function (helper):
   - If node has only one child (left or right), return that child.
   - If node has both children:
       - Find the rightmost node of its left subtree (lastRight).
       - Attach the right subtree of the node being deleted to lastRight->right.
       - Return the left child (which now has merged right subtree).
2. Delete Operation (deleteNode):
   - If root is NULL → return NULL.
   - If root->val == key → return helper(root) (delete root).
   - Otherwise, traverse tree using a pointer (curr):
       - If key < curr->val:
           - Check left child:
               - If left child is target → replace with helper(left).
               - Else move curr = curr->left.
       - If key > curr->val:
           - Check right child:
               - If right child is target → replace with helper(right).
               - Else move curr = curr->right.
3. Return root after deletion.

⚠️ Assumptions:
- Standard BST property holds: left < root < right.
- Key is guaranteed to exist in tree (else function returns unchanged tree).

🕒 Time Complexity: O(h)
   - h = height of tree → O(log n) for balanced BST, O(n) for skewed tree.

🧠 Space Complexity: O(1)
   - No extra recursion stack (iterative approach).
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *findlastright(TreeNode *root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}
TreeNode *helper(TreeNode *root)
{
    if (root->left == nullptr)
    {
        return root->right;
    }
    else if (root->right == nullptr)
    {
        return root->left;
    }
    TreeNode *leftChildren = root->left;
    TreeNode *rightChildren = root->right;
    TreeNode *lastRight = findlastright(leftChildren);
    lastRight->right = rightChildren;

    return leftChildren;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (root->val == key)
    {
        return helper(root);
    }
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->val > key)
        {
            if (curr->left != nullptr && curr->left->val == key)
            {
                curr->left = helper(curr->left);
            }
            else
            {
                curr = curr->left;
            }
        }
        else
        {
            if (curr->right != nullptr && curr->right->val == key)
            {
                curr->right = helper(curr->right);
            }
            else
            {
                curr = curr->right;
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