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
string serialize(TreeNode *root)
{
    string ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto element = q.front();
        q.pop();
        if (element == nullptr)
        {
            ans += "N,";
        }
        else
        {
            ans += to_string(element->val) + ",";
            q.push(element->left);
            q.push(element->right);
        }
    }
    ans.pop_back();

    return ans;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.empty())
        return nullptr;
    stringstream ss(data);
    string token;
    getline(ss, token, ',');
    if (token == "N")
        return nullptr;
    TreeNode *root = new TreeNode(stoi(token));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto element = q.front();
        q.pop();
        if (getline(ss, token, ','))
        {
            if (token != "N")
            {
                element->left = new TreeNode(stoi(token));
                q.push(element->left);
            }
        }
        if (getline(ss, token, ','))
        {
            if (token != "N")
            {
                element->right = new TreeNode(stoi(token));
                q.push(element->right);
            }
        }
    }
    return root;
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

    return 0;
}