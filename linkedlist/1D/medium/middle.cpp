#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode()
    {
        data = 0;
        next = NULL;
    }

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

ListNode *constructLL(vector<int> &arr)
{
    if (arr.empty())
        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void printLL(ListNode *head)
{
    ListNode *temp = head;
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

int getMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) // be careful with && and ||
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    vector<int> v1 = {1, 2, 8};
    ListNode *head = constructLL(v1);
    printLL(head);
    cout << getMiddle(head);
    return 0;
}