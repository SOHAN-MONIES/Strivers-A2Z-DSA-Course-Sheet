// URL: https://leetcode.com/problems/same-tree/description/
#include <bits/stdc++.h>
using namespace std;

// Algorithm
// Check if both are null
// Check if one of them is null
// Check if both are not null , then check their values
// And traverse them together with recursion on both left and right side;

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    if (p == nullptr || q == nullptr)
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    
    return 0;
}