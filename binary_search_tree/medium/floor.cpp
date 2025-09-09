// URL: https://www.geeksforgeeks.org/problems/floor-in-bst/1
#include <bits/stdc++.h>
using namespace std;

int floor(Node *root, int x)
{
    int ans = -1;
    while (root)
    {
        if (root->data > x)
        {
            root = root->left;
        }
        else
        {
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}
int main()
{

    return 0;
}