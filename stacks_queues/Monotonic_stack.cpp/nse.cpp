#include <vector>
#include <stack>
using namespace std;

vector<int> next_smaller_element(vector<int> arr)
{
    int n = arr.size();
    vector<int> nse(n,n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            nse[i] = -1;
        }
        else
        {
            nse[i] = st.top();
        }

        st.push(arr[i]);
    }

    return nse;
}
