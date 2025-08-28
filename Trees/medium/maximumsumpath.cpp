// URL: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
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

int helper(TreeNode *node, int &distance)
{
    if (node == nullptr)
    {
        return 0;
    }
    int leftsum = max(0, helper(node->left, distance));
    int rightsum = max(0, helper(node->right, distance));
    distance = max(distance, leftsum + rightsum + node->val);
    return max(leftsum, rightsum) + node->val;
}

int maxPathSum(TreeNode *root)
{
    int distance = INT_MIN;
    helper(root, distance);
    return distance;
}
int dfs(TreeNode *root, int &ans)
{
    if (root == nullptr)
    {
        return 0;
    }
    int lt = max(0, dfs(root->left, ans));
    int rt = max(0, dfs(root->right, ans));
    ans = max(ans, root->val + lt + rt);
    return max(lt, rt) + root->val;
}

int findMaxSum(TreeNode *root)
{
    // code here
    int ans = 0;
    dfs(root, ans);
    return ans;
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
    cout << maxPathSum(root);
    cout << findMaxSum(root);
    return 0;
}