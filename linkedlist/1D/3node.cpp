#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
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
        cout << temp->data << "->" << temp->next << endl;
        temp = temp->next;
    }
}