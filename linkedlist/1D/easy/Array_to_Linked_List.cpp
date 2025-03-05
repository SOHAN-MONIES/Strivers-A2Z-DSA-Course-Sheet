// URL: https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1
#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int val)
    {
        data = val;
        next = NULL;
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

ListNode *deletehead(ListNode *head)
{
    if (head == NULL)
        return head;
    ListNode *temp = head;
    head = head->next;
    delete temp;
    return head;
}

ListNode *deleteTail(ListNode *head)
{

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    ListNode *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

ListNode *deleteNode(ListNode *head, int x)
{
    if (head == nullptr)
        return nullptr;
    if (x == 1)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    ListNode *temp = head;
    ListNode *prev = NULL;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == x)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

ListNode *deleteNodevalue(ListNode *head, int x)
{
    if (head == nullptr)
        return nullptr;
    if (head->data == x)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    ListNode *temp = head;
    ListNode *prev = NULL;

    while (temp != NULL)
    {

        if (x == temp->data)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

ListNode *insertHead(ListNode *head, int x)
{
    ListNode *temp = new ListNode(x);
    temp->next = head;
    return temp;
}

ListNode *insertTail(ListNode *head, int x)
{

    if (head == NULL)
    {
        ListNode *temp = new ListNode(x);
        return temp;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ListNode *el = new ListNode(x);
    temp->next = el;
    return head;
}

ListNode *InsertPosition(ListNode *head, int pos, int element)
{
    if (head == NULL)
    {
        if (pos == 1)
        {
            return new ListNode(element);
        }
        else
            return NULL;
    }
    if (pos == 1)
    {
        ListNode *temp = new ListNode(element);
        temp->next = head;
        head = temp;
    }
    int cnt = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == pos - 1)
        {
            ListNode *ele = new ListNode(element);
            ele->next = temp->next;
            temp->next = ele;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> v1 = {1, 2, 3};
    ListNode *head = constructLL(v1);
    printLL(head);
    ListNode *head2 = InsertPosition(head, 5, 5);
    printLL(head2);

    return 0;
}