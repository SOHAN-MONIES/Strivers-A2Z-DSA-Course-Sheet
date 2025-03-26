// URL:
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int l, int h)
{
    if (l >= h)
    {
        return true;
    }
    if (s[l] != s[h])
    {
        return false;
    }
    return  isPalindrome(s, l + 1, h - 1);
}

int main()
{
    cout << isPalindrome("hassah", 0, 5);
    // "hassah"
    return 0;
}