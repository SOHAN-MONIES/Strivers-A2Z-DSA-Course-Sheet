// URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/
#include <bits/stdc++.h>
using namespace std;

// Level Order Solution
int maxDepth(TreeNode *root)
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

    return 0;
}