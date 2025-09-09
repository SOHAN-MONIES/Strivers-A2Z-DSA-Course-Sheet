// URL: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
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

int helper(Node *node, int &distance)
{
    if (node == nullptr)
    {
        return 0;
    }
    int leftsum = max(0, helper(node->left, distance));
    int rightsum = max(0, helper(node->right, distance));
    distance = max(distance, leftsum + rightsum + node->data);
    return max(leftsum, rightsum) + node->data;
}

int maxPathSum(Node *root)
{
    int distance = INT_MIN;
    helper(root, distance);
    return distance;
}
int dfs(Node *root, int &ans)
{
    if (root == nullptr)
    {
        return 0;
    }
    int lt = max(0, dfs(root->left, ans));
    int rt = max(0, dfs(root->right, ans));
    ans = max(ans, root->data + lt + rt);
    return max(lt, rt) + root->data;
}

int findMaxSum(Node *root)
{
    // code here
    int ans = 0;
    dfs(root, ans);
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
    cout << maxPathSum(root);
    cout << findMaxSum(root);
    return 0;
}