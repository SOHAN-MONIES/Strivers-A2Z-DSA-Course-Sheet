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

ListNode *ReverseLL(ListNode *head2)
{
    ListNode *prev = NULL;
    if (head2 == NULL || head2->next == NULL)
        return head2;
    ListNode *temp = head2;
    while (temp != NULL)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head->next == NULL)
        return true;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *first = head;
    ListNode *second = ReverseLL(slow->next);
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            ReverseLL(second);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    ReverseLL(second);
    return true;
}