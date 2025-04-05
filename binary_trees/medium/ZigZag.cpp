// URL:https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
#include <bits/stdc++.h>
using namespace std;
/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL)
    {
        return res;
    }
    bool leftToRight = true;
    queue<TreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        int n = q1.size();
        vector<int> level(n);
        for (int i = 0; i < n; i++)
        {
            TreeNode *element = q1.front();
            q1.pop();
            int index = leftToRight ? i : (n - i - 1); // find whether movement is right to left or left to right
            level[index] = element->val;
            if (element->left)
            {
                q1.push(element->left);
            }
            if (element->right)
            {
                q1.push(element->right);
            }
        }
        res.push_back(level);
        leftToRight = !leftToRight;
    }
    return res;
}

int main()
{

    return 0;
}