// URL: https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

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

int main()
{

    return 0;
}