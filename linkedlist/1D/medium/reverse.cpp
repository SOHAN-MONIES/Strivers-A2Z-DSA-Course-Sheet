#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode()
    {
        data = 0;
        next = NULL;
    }

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

ListNode *constructLL(vector<int> &arr)
{
    if (arr.empty())
        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void printLL(ListNode *head)
{
    ListNode *temp = head;
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

// Node *reverseList(struct Node *head)
// {
//     Node *temp = head;
//     stack<int> st;
//     while(temp!=NULL){
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp!=NULL){
//         temp->data = st.top();
//         st.pop();
//         temp = temp->next;
//     }
//     return head;
// }

ListNode *reverseList(struct ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main()
{
    vector<int> v1 = {1, 2, 3};
    ListNode *head = constructLL(v1);
    printLL(head);
    ListNode *head2 = reverseList(head);
    printLL(head2);
    return 0;
}