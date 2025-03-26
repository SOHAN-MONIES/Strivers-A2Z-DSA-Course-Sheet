// URL: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
#include <bits/stdc++.h>
using namespace std;
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

int main()
{

    return 0;
}