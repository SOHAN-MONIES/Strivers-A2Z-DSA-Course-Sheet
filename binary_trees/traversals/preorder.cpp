#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> v1;
    if (root == NULL)
    {
        return v1;
    }
    v1.push_back(root->val);
    vector<int> left = preorderTraversal(root->left);
    v1.insert(v1.end(), left.begin(), left.end());
    vector<int> right = preorderTraversal(root->right);
    v1.insert(v1.end(), right.begin(), right.end());
    return v1;
}

int main()
{
    // Create a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Perform preorder traversal
    vector<int> result = preorderTraversal(root);

    // Print the result
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up dynamically allocated memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
