// URL: https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *constructLL(vector<int> &arr)
{
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

int printLength(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

bool searchKey(Node *head, int key)
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
int main()
{
    vector<int> v1 = {2,1, 2, 3, 4, 5,9};
    Node* head = constructLL(v1);
    printLL(head);
    cout << printLength(head) << endl;
    cout << searchKey(head, 15);
    return 0;
}