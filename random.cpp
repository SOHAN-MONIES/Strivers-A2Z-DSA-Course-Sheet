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
void dfs(TreeNode *root1, TreeNode *root2, int &flag)
{
    if (root1 == nullptr && root2 != nullptr)
    {
        flag = 0;
        return;
    }
    else if (root1 != nullptr && root2 == nullptr)
    {
        flag = 0;
        return;
    }
    else if (root1 == nullptr && root2 == nullptr)
    {
        return;
    }
    else
    {
        if (root1->val != root2->val)
        {
            flag = 0;
            return;
        }
    }
    dfs(root1->left, root2->left, flag);
    dfs(root1->right, root2->right, flag);
}
bool isSameTree(TreeNode *p, TreeNode *q)
{
    int flag = 1;
    dfs(p, q, flag);
    return flag != 0;
}
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;            // both are nullptr
    if (!p || !q) return false;           // one is nullptr, other is not
    if (p->val != q->val) return false;   // values differ
    
    // recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    cout << isSameTree(root, root1);
    return 0;
}