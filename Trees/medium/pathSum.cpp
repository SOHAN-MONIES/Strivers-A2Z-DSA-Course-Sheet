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
bool helper(TreeNode *root, int targetSum)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        if (targetSum == root->val)
        {
            return true;
        }
        return false;
    }
    return helper(root->left, targetSum - root->val) || helper(root->right, targetSum - root->val);
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    return helper(root, targetSum);
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
    hasPathSum(root, 21);
    return 0;
}