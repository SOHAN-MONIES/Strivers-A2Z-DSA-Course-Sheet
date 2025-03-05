// URL:
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int data1, ListNode *next1)
    {
        data = data1;
        next = next1;
    }
};

int main()
{
    int arr[5] = {0, 1, 2, 3, 4};
    ListNode *first = new ListNode(arr[0], nullptr);
    cout << first->next;
    return 0;
}