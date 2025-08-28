// URL:
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
class Solution
{
public:
    unordered_map<int, int> inorderIdx;
    int postIdx;

    Node *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderIdx[inorder[i]] = i;
        }
        postIdx = postorder.size() - 1;

        return dfs(0, inorder.size() - 1, postorder);
    }

private:
    Node *dfs(int l, int r, vector<int> &postorder)
    {
        if (l > r)
        {
            return nullptr;
        }

        Node *root = new Node(postorder[postIdx--]);
        int idx = inorderIdx[root->data];
        root->right = dfs(idx + 1, r, postorder);
        root->left = dfs(l, idx - 1, postorder);
        return root;
    }
};

int main()
{

    return 0;
}