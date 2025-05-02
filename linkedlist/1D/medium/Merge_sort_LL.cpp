#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *next;

    TreeNode()
    {
        data = 0;
        next = NULL;
    }

    TreeNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

TreeNode *constructLL(vector<int> &arr)
{
    if (arr.empty())
        return NULL;
    TreeNode *head = new TreeNode(arr[0]);
    TreeNode *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        TreeNode *temp = new TreeNode(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void printLL(TreeNode *head)
{
    TreeNode *temp = head;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            cout << temp->data;
        }
        else
        {
            cout << temp->data << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Node *mergeSort(Node *head)
// {
//     Node *temp = head;
//     vector<int> v1;
//     while (temp != NULL)
//     {
//         v1.push_back(temp->data);
//         temp = temp->next;
//     }
//     sort(v1.begin(), v1.end());
//     temp = head;
//     int i = 0;
//     while (temp != NULL)
//     {
//         temp->data = v1[i];
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }

TreeNode *mergeSort(TreeNode *head)
{
}

int main()
{
    vector<int> v1 = {1, 2, 3, 5, 6, 0};
    TreeNode *head = constructLL(v1);
    printLL(head);
    TreeNode *head1 = mergeSort(head);
    printLL(head1);
    return 0;
}