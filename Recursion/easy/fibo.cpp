// URL:
#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n < 2)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int a = fib(4);
    return 0;
}