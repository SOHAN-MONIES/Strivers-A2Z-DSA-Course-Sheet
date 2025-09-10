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
// BRUTEFORCE
//  void helper(TreeNode *root, vector<int> &ans)
//  {
//      if (root == nullptr)
//      {
//          return;
//      }
//      helper(root->left, ans);
//      ans.push_back(root->val);
//      helper(root->right, ans);
//  }

// vector<int> dfs(TreeNode *root)
// {
//     vector<int> ans;
//     helper(root, ans);
//     return ans;
// }

// int kthSmallest(TreeNode *root, int k)
// {
//     vector<int> inorder = dfs(root);
//     return inorder[k - 1];
// }
void dfs(TreeNode *root, int k, int &ans)
{
    if (root == nullptr)
    {
        return;
    }

    dfs(root->left, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->val;
        return;
    }
    dfs(root->right, k, ans);
}

int kthSmallest(TreeNode *root, int k)
{
    int ans = -1;
    dfs(root, k, ans);
    return ans;
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
    cout << kthSmallest(root, 1);
    return 0;
}