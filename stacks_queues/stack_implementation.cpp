// URL:
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(1); //{1}
    st.push(5); //{1 5}
    st.push(3); //{1 5 3}
    st.push(2); //{1,5,3,2}
    st.pop();
    cout << st.empty() << endl;
    cout << st.size() << endl;
    cout << st.top() << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}