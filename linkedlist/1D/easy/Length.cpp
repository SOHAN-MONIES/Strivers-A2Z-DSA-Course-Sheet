// URL: https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0
#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;

    // Default constructor
    ListNode()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int printLength(ListNode *head)
{
    int cnt = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
