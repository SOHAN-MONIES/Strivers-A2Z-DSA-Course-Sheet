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

int main() {
    vector<int> v1 = {1, 2, 3};
    Node* head = constructLL(v1);
    printLL(head);
    return 0;
}