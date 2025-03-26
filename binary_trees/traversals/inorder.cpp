// URL: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
#include <bits/stdc++.h>
using namespace std;

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> v1;
    if (root == NULL)
    {
        return v1;
    }
    vector<int> left = inorderTraversal(root->left);
    v1.insert(v1.end(), left.begin(), left.end());
    v1.push_back(root->val);
    vector<int> right = inorderTraversal(root->right);
    v1.insert(v1.end(), right.begin(), right.end());
    return v1;
}

int main() {
    
    return 0;
}