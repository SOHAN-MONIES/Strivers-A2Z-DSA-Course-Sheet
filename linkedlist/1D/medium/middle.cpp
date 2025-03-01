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

// int givecount(Node *head)
// {
//     Node *temp = head;
//     int cnt = 0;
//     while (temp != NULL)
//     {
//         cnt++;
//         temp = temp->next;
//     }
//     return cnt / 2 + 1;
// }

// int getMiddle(Node *head)
// {
//     int middle_pos = givecount(head);
//     int cnt = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cnt++;
//         if (cnt == middle_pos)
//         {
//             return temp->data;
//         }
//         temp = temp->next;
//     }
//     return -1;
// }

int getMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)// be careful with && and ||
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}



int main()
{
    vector<int> v1 = {1, 2,8};
    Node *head = constructLL(v1);
    printLL(head);
    cout << getMiddle(head);
    return 0;
}