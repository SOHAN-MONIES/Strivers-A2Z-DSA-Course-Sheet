#include <bits/stdc++.h>
using namespace std;

// BRUTEFORCE
//  vector<int> nextLargerElement(vector<int> &arr)
//  {
//      int n = arr.size();
//      vector<int> nge(n, 0);
//      for (int i = 0; i < n; i++)
//      {
//          for (int j = i + 1; j <= i+n-1; j++)  // x - i+1=n solve for x
//          {
//              int ind = j % n;
//              if (arr[ind] > arr[i])
//              {
//                  nge[i]=arr[ind];
//                  break;
//              }
//          }
//          if (nge[i] == 0)
//          {
//              nge[i] = -1;
//          }
//      }
//      return nge;
//  }

vector<int> nextLargerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i % n])
        {
            st.pop();
        }
        if (i < n)
        {
            nge[i] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i % n]);
    }
    return nge;
}

int main()
{
    vector<int> v1 = {4, 7, 6};
    vector<int> v2 = nextLargerElement(v1);
    for (auto num : v2)
    {
        cout << num << " ";
    }
    return 0;
    // 4 7 6 4 7 6
}