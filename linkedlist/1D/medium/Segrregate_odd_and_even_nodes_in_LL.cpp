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

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    ListNode *head = constructLL(v1);
    printLL(head);
    ListNode *head1 = oddEvenList(head);
    printLL(head1);
    return 0;
}