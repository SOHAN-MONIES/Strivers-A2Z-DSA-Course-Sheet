// URL:https://leetcode.com/problems/search-in-a-binary-search-tree/
#include <bits/stdc++.h>
using namespace std;

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->val == val)
    {
        return root;
    }
    if (root->val > val)
    {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}
int main()
{

    return 0;
}