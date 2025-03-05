// URL: https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    struct ListNode *next;

    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
};

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

int main()
{

    return 0;
}