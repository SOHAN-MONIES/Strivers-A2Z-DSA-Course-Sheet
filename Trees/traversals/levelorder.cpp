// URL: https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *element = q.front();
            q.pop();
            if (element->left != NULL)
                q.push(element->left);
            if (element->right != NULL)
                q.push(element->right);
            level.push_back(element->val);
        }
        ans.push_back(level);
    }
    return ans;
}
int main()
{

    return 0;
}