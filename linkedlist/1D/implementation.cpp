// URL:
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

int main()
{
    vector<int> arr = {1, 2, 4};
    Node *y = new Node(arr[0], NULL);
    cout << y->data << " " << y->next << endl;
}