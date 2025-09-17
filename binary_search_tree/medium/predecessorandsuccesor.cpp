#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
vector<Node *> findPreSuc(Node *root, int key)
{
    // code here
    Node *successor = NULL;
    Node *curr = root;
    while (curr)
    {
        if (curr->data > key)
        {
            successor = curr;
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    Node *predecessor = NULL;
    curr = root;
    while (curr)
    {
        if (curr->data >= key)
        {
            curr = curr->left;
        }
        else
        {
            predecessor = curr;
            curr = curr->right;
        }
    }
    return {predecessor, successor};
}
int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);

    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    root->right->left = new Node(6);
    root->right->left->right = new Node(7);

    root->right->right = new Node(9);
    root->right->right->right = new Node(10);

    return 0;
}