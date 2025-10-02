#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    cout << q1.back() << endl;

    // Dequeue and print elements until the queue is empty
    while (!q1.empty())
    {
        cout << q1.front() << " "; // Print the front element
        q1.pop();                  // Remove the front element
    }

    return 0;
}