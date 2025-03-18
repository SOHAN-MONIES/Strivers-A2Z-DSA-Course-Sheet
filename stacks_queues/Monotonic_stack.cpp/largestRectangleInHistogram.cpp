// URL: https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
#include <bits/stdc++.h>
using namespace std;

vector<int> next_smaller_element(vector<int> arr)
{
    int n = arr.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nse[i] = st.top();
        }

        st.push(i);
    }

    return nse;
}

vector<int> previous_smaller_element(vector<int> arr)
{
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}

int getMaxArea(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse = next_smaller_element(arr);
    vector<int> pse = previous_smaller_element(arr);
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int width = (nse[i] - pse[i] - 1);
        area = max(area, arr[i] * width);
    }
    return area;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int element = st.top();
            st.pop();
            int nse = i;                          // Next Smaller Element
            int pse = st.empty() ? -1 : st.top(); // Previous Smaller Element
            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int nse = n;
        int element = st.top();
        st.pop(); // Corrected: pop the element
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, heights[element] * (nse - pse - 1));
    }

    return maxArea;
}

int main()
{
    vector<int> v1 = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(v1);
    return 0;
}