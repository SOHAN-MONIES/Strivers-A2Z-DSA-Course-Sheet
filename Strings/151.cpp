// URL:https://leetcode.com/problems/reverse-words-in-a-string/
#include <bits/stdc++.h>
using namespace std;

string reverse(string s)
{
    int x = 0;
    int y = s.length() - 1;
    while (x < y)
    {
        swap(s[x], s[y]);
        x++;
        y--;
    }
    return s;
}

string reverseWords(string s)
{
    string rev;
    vector<string> st;
    string word = "";
    for (int i = 0; i < s.length(); i++)
    {

        if (iswalnum(s[i]))
        {
            word += s[i];
        }
        if ((isspace(s[i]) || i == s.length() - 1) && word != "")
        {
            st.push_back(word);
            word = "";
        }
    }
    for (int i = 0; i < st.size(); i++)
    {
        rev += reverse(st[i]);
        if (i != st.size() - 1)
        {
            rev += " ";
        }
    }
    return rev;
}
int main()
{
    cout << reverseWords(" i like this program very much ");

    return 0;
}