#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(Node *root)
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

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
