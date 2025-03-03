#include <iostream>
using namespace std;

struct Node
{

    int data;
    Node *next;


    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    first->next = second;
    second->next = third; 
    third->next = NULL;

    Node *temp = first;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            cout << temp->data<<endl;
        }
        else
        {
            cout << temp->data << "->";
        }
        temp = temp->next;
    }
}