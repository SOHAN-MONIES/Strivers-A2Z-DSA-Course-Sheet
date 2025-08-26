// URL:
#include <bits/stdc++.h>
using namespace std;

vector<int> preOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *element = st.top();
        st.pop();
        ans.push_back(element->data);
        if (element->right != NULL)
        {
            st.push(element->right);
        }
        if (element->left != NULL)
        {
            st.push(element->left);
        }
    }

    return ans;
}

int main()
{

    return 0;
}