#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *constructLL(vector<int> &arr)
{
    if (arr.empty())
        return NULL;
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
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

Node *mergeSort(Node *head)
{
}

int main()
{
    vector<int> v1 = {1, 2, 3, 5, 6, 0};
    Node *head = constructLL(v1);
    printLL(head);
    Node *head1 = mergeSort(head);
    printLL(head1);
    return 0;
}