// URL:https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
#include <bits/stdc++.h>
using namespace std;

int findCeil(Node *root, int x)
{
    // code here
    int ans = -1;
    while (root)
    {
        if (root->data == x)
        {
            return root->data;
        }
        else if (root->data < x)
        {
            root = root->right;
        }
        else
        {
            ans = root->data;
            root = root->left;
        }
    }
    return ans;
}
int main()
{

    return 0;
}