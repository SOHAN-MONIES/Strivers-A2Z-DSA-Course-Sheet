// URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
// Level Order Solution
int maxDepthl(TreeNode *root)
{
    int depth = 0;
    if (root == nullptr)
        return depth;
    queue<TreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        int n = q1.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *element = q1.front();
            q1.pop();
            if (element->left)
            {
                q1.push(element->left);
            }
            if (element->right)
            {
                q1.push(element->right);
            }
        }
        depth++;
    }
    return depth;
}

// Recursive Solution
int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
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
    cout << maxDepth(root);
    return 0;
}