// URL: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=infix-to-postfix
#include <bits/stdc++.h>

using namespace std;

int priorityAssignment(char c)
{
    if (c == '^')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    else
    {
        return 0;
    }
}

bool priority(char c1, char c2)
{
    return priorityAssignment(c1) >= priorityAssignment(c2);
}

string infixToPostfix(const string &s)
{
    int i = 0;
    stack<char> st;
    string ans;
    while (i < s.size())
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans.push_back(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(st.top(), s[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    cout << infixToPostfix("a+b*(c^d-e)^(f+g*h)-i")<<endl;
    return 0;
}