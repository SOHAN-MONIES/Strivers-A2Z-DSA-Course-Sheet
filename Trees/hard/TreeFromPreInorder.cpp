// URL: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
#include <bits/stdc++.h>
using namespace std;

// Build Index Map: Store the indices of inorder elements in a map for fast look-up.

// Recursive DFS: Define a recursive dfs function to construct the tree using preorder and inorder sequences.

// Base Case: If the left index exceeds right, return nullptr.

// Root Creation: Create the root node from the current element in preorder, then find its position in inorder using the map.

// Recursion: Recursively build the left and right subtrees by adjusting the search range in inorder.

// This will help you recall the logic quickly when revisiting the code.

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

Node *dfs(vector<int> &preorder, int l, int h, int &pre_index, unordered_map<int, int> &mpp)
{
    if (l > h)
    {
        return nullptr;
    }
    Node *root = new Node(preorder[pre_index]);
    int mid = mpp[preorder[pre_index]];
    pre_index++;

    root->left = dfs(preorder, l, mid - 1, pre_index, mpp);
    root->right = dfs(preorder, mid + 1, h, pre_index, mpp);

    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int pre_index = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mpp[inorder[i]] = i;
    }
    return dfs(preorder, 0, inorder.size() - 1, pre_index, mpp);
}

int main()
{

    return 0;
}