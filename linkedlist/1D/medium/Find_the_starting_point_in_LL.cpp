#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* constructLL(vector<int>& arr) {
    if (arr.empty()) return NULL;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->next == NULL) {
            cout << temp->data;
        } else {
            cout << temp->data << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Node *findFirstNode(Node *head)
// {
//     unordered_map<Node *, int> mpp;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         mpp[temp]++;
//         if (mpp[temp] == 2)
//         {
//             return temp;
//         }
//         temp = temp->next;
//     }
//     return NULL;
// }

Node *findFirstNode(Node *head){
    Node *slow = head;
    Node *fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

    int main()
{
    vector<int> v1 = {1, 2, 3};
    Node* head = constructLL(v1);
    printLL(head);
    return 0;
}