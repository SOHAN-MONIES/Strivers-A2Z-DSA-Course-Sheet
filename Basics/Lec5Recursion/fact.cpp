// URL:https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty%255B%255D=-1&page=1&query=problemTypefunctionaldifficulty%255B%255D-1page1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long fact(long long n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    cout << fact(20);
    return 0;
}