#include <bits/stdc++.h>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void dfs(vector<string> &res, string &s, TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (!s.empty())
    {
        s += "->";
    }
    s += to_string(root->val);

    if (root->left == nullptr && root->right == nullptr)
    {

        res.push_back(s);
    }
    else
    {
        dfs(res, s, root->left);
        dfs(res, s, root->right);
    }
    s.pop_back();
    s.pop_back();
    s.pop_back();
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> res;
    string s;
    dfs(res, s, root);

    return res;
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
    vector<string> ans = binaryTreePaths(root);
    for (auto ele : ans)
    {
        cout << ele << endl;
    }
    return 0;
}