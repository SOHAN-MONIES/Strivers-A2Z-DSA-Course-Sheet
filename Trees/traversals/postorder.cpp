// URL:https://leetcode.com/problems/binary-tree-postorder-traversal/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

void inorder_helper(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    inorder_helper(root->left, ans);
    inorder_helper(root->right, ans);
    ans.push_back(root->val);
}

vector<int> inorderTraversal(Node *root)
{
    vector<int> ans;
    inorder_helper(root, ans);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    vector<int> ans = inorderTraversal(root);
    for (auto ele : ans)
    {
        cout << ele << endl;
    }
    return 0;
}
