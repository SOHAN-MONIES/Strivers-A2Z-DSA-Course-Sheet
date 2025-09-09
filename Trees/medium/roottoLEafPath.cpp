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
void dfs(Node *root, vector<vector<int>> &ans, vector<int> &temp) {
    if (!root) return;

    temp.push_back(root->data);

    if (!root->left && !root->right) {
        ans.push_back(temp);
        temp.pop_back();   // done, backtrack
        return;
    }

    dfs(root->left, ans, temp);
    dfs(root->right, ans, temp);

    temp.pop_back();       // done with this node
}

vector<vector<int>> Paths(Node *root)
{
    // code here
    vector<vector<int>> ans;
    vector<int> temp;
    dfs(root, ans, temp);
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> ans = Paths(root);
    for (auto row : ans)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}