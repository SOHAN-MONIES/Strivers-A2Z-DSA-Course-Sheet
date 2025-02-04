// URL:
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