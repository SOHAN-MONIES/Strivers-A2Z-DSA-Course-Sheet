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

// ListNode *removeNthFromEnd(ListNode *head, int n)
// {
//     if (head == NULL)
//         return NULL;
//     ListNode *temp = head;
//     int cnt = 0;
//     while (temp != NULL)
//     {
//         cnt++;
//         temp = temp->next;
//     }
//     if (cnt == n)
//     {
//         ListNode *newHead= head->next;
//         delete head;
//         return newHead;
//     }
//     if (n > cnt)
//     {
//         return head;
//     }
//     int res = cnt - n;
//     cnt = 0;
//     temp = head;
//     while (temp != NULL)
//     {
//         cnt++;
//         if (cnt == res)
//         {
//             break;
//         }
//         else

//             temp = temp->next;
//     }
//     ListNode *delNode = temp->next;
//     temp->next = temp->next->next;
//     delete delNode;
//     return head;
// }

ListNode *removeNthFromEnd(ListNode *head, int n)
{


    ListNode *fast = head;
    ListNode *slow = head;
    for (int i = 0; i <n; i++)
    {
        fast = fast->next;
    }
    if(fast==NULL){
        return head->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}

int main()
{
    vector<int> v1 = {1,2,3,4,5};
    ListNode *head = constructLL(v1);
    printLL(head);
    ListNode *head1 = removeNthFromEnd(head, 5);
    printLL(head1);
    return 0;
}