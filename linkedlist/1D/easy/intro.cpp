// URL: 
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
};

int main() {
    int arr[5] = {0, 1, 2, 3, 4};
    Node* first = new Node(arr[0], nullptr);
    cout << first->next;
    return 0;
}