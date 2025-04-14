// URL: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
#include <bits/stdc++.h>
using namespace std;

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mpp[inorder[i]] = i;
    }
    TreeNode *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mpp)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[preStart]);
    int inRoot = mpp[root->val];
    int numLeft = inRoot - inStart;
    root->left = buildTree(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, mpp);
    root->right = buildTree(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mpp);
    return root;
}

int main()
{

    return 0;
}