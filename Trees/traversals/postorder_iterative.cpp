// URL:
#include <bits/stdc++.h>
using namespace std;

vector<int> postOrder(Node *node)
{
    vector<int> ans;
    if (node == NULL)
        return ans;

    stack<Node *> st;
    st.push(node);

    while (!st.empty())
    {
        Node *element = st.top();
        st.pop();

        // Add the node's data to the result vector
        ans.push_back(element->data);

        // Push left child first, then right child onto the stack
        if (element->left != NULL)
            st.push(element->left);
        if (element->right != NULL)
            st.push(element->right);
    }

    // Reverse the vector to get the correct post-order traversal
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}