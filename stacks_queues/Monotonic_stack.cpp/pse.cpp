// URL: https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/0
#include <bits/stdc++.h>
using namespace std;

vector<int> previous_smaller_element(vector<int> arr)
{
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            pse[i] = -1;
        }
        else
        {
            pse[i] = st.top();
        }
        st.push(arr[i]);
    }
    return pse;
}

int main()
{

    return 0;
}