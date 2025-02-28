// URL: https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
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

Node *deletehead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node *deleteNode(Node *head, int x)
{
    if (head == nullptr)
        return nullptr;
    if (x == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
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

Node *deleteNodevalue(Node *head, int x)
{
    if (head == nullptr)
        return nullptr;
    if (head->data == x)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;

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

Node *inserthead(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

Node *inserthead(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

int main()
{
    vector<int> v1 = {};
    Node *head = constructLL(v1);
    printLL(head);
    Node *head2 = inserthead(head, 2);
    printLL(head2);

    return 0;
}