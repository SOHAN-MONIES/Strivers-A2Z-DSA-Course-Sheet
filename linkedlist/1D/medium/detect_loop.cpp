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
// TC->O(N) and SC->O(N)
// bool detectLoop(Node *head)
// {
//     unordered_map<Node *, int> mpp;
//     Node *temp = head;
//     while (temp!=NULL)
//     {
//         if(mpp.find(temp)!=mpp.end()){
//             return true;
//         }
//         mpp[temp]++;
//         temp = temp->next;
//     }
//     return false;
// }

bool detectLoop(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> v1 = {1, 2, 3};
    ListNode *head = constructLL(v1);
    printLL(head);
    return 0;
}