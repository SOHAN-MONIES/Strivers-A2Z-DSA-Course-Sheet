#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
bool dfs(Node *node1, Node *node2)
{
    if (node1 != nullptr && node2 != nullptr)
    {
        if (node1->data != node2->data)
            return false;
    }
    else if (node1 == nullptr && node2 == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
    bool ans1 = dfs(node1->left, node2->right);
    bool ans2 = dfs(node1->right, node2->left);
    return ans1 && ans2;
}

bool isSymmetric(Node *root)
{
    return dfs(root->left, root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->right = new Node(3);
    root->right->right = new Node(3);
    cout << isSymmetric(root);
    return 0;
}