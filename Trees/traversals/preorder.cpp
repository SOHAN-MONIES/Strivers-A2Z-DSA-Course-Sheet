// URL:https://leetcode.com/problems/binary-tree-inorder-traversal/description/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(left),right(right) {}
};

void preorder_helper(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    ans.push_back(root->val);
    preorder_helper(root->left, ans);
    preorder_helper(root->right, ans);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    preorder_helper(root, ans);
    return ans;
}




int main() {
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->left=new TreeNode(8);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    root->right->right->left=new TreeNode(9);
    root->right->right->right=new TreeNode(10);
    vector<int>ans=postorderTraversal(root);
    for (auto ele:ans) {
        cout<<ele<<endl;
    }
    return 0;
}
