// URL: https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

bool searchKey(int n, Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (key == temp->data)
            return true;
        temp = temp->next;
    }
    return false;
}