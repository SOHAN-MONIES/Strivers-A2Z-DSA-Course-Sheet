// URL: https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
};

bool searchKey(int n, ListNode *head, int key)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        if (key == temp->data)
            return true;
        temp = temp->next;
    }
    return false;
}