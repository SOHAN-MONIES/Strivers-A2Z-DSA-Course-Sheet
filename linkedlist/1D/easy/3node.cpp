#include <iostream>
using namespace std;

struct ListNode
{

    int data;
    ListNode *next;

    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

int main()
{
    ListNode *first = new ListNode(10);
    ListNode *second = new ListNode(20);
    ListNode *third = new ListNode(30);

    first->next = second;
    second->next = third;
    third->next = NULL;

    ListNode *temp = first;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            cout << temp->data << endl;
        }
        else
        {
            cout << temp->data << "->";
        }
        temp = temp->next;
    }
}